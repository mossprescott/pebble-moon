#include <pebble.h>

#include "astronomy.h"
#include "colors.h"
#include "graph.h"
#include "moon.h"
#include "sync.h"

static Window      *window;

static TextLayer   *time_layer;
static TextLayer   *date_layer;

static GBitmap     *moon_bitmap;
static BitmapLayer *moon_layer;

static Layer       *graph_layer;
static GraphData   *graph_data;

static void init_moon() {
  int size = 108;
#ifdef PBL_PLATFORM_APLITE
  moon_bitmap = gbitmap_create_blank((GSize) { .w = size, .h = size });
#else
  // TODO: check PBL_COLOR?
  moon_bitmap = gbitmap_create_blank((GSize) { .w = size, .h = size }, GBitmapFormat8Bit);
#endif  
}

static void init_graph_data() {
  graph_data->now = 0;

  for (int i=0; i < 144; i += 1) {
    int16_t s = i-75;
    graph_data->sun[i] = 0.75 - s*s*0.0002; // HACK: should be NO_DATA
    int16_t m = i-30;
    graph_data->moon[i] = 0.5 - m*m*0.0004; // HACK: should be NO_DATA
  }
}

static void set_day_night_mode(bool isDay) {
  // GColor fg = isDay ? DAY_FG : NIGHT_FG;
  // GColor bg = isDay ? DAY_BG : NIGHT_BG;
  
  window_set_background_color(window, UI_BG(isDay));
  text_layer_set_background_color(time_layer, UI_BG(isDay));
  text_layer_set_text_color(time_layer, UI_FG(isDay));
  text_layer_set_background_color(date_layer, UI_BG(isDay));
  text_layer_set_text_color(date_layer, UI_FG(isDay));
  
  graph_data->isDay = isDay;
}

static void update_graph_proc(Layer *layer, GContext *ctx) {
  render_graph(ctx, graph_data);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  time_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { 60, 30 } });
  text_layer_set_font(time_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28));
  text_layer_set_text_alignment(time_layer, GTextAlignmentRight);
  text_layer_set_text(time_layer, "12:34");
  layer_add_child(window_layer, text_layer_get_layer(time_layer));
  
  date_layer = text_layer_create((GRect) { .origin = { bounds.size.w-60, 0 }, .size = { 60-2, 30 } });
  text_layer_set_font(date_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text_alignment(date_layer, GTextAlignmentRight);
  text_layer_set_text(date_layer, "1 Sun");
  layer_add_child(window_layer, text_layer_get_layer(date_layer));

#ifdef PBL_PLATFORM_APLITE
  GRect moon_bounds = moon_bitmap->bounds;
#else
  GRect moon_bounds = gbitmap_get_bounds(moon_bitmap);
#endif
  uint16_t size = moon_bounds.size.w;
  moon_layer = bitmap_layer_create((GRect) { 
    .origin = { bounds.size.w/2 - size/2, 30 },
    .size = moon_bounds.size });
  bitmap_layer_set_bitmap(moon_layer, moon_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(moon_layer));
  
  graph_layer = layer_create_with_data((GRect) { 
    .origin = { 0, bounds.size.h - GRAPH_HEIGHT },
    .size = { bounds.size.w, GRAPH_HEIGHT } }, 
    sizeof(GraphData));
  graph_data = (GraphData *) layer_get_data(graph_layer);
  init_graph_data();
  layer_set_update_proc(graph_layer, update_graph_proc);
  layer_add_child(window_layer, graph_layer);
}

static void window_unload(Window *window) {
  text_layer_destroy(time_layer);
  text_layer_destroy(date_layer);
  
  gbitmap_destroy((GBitmap *) bitmap_layer_get_bitmap(moon_layer));
  bitmap_layer_destroy(moon_layer);
}

static bool is_day(struct tm* tick_time) {
//   return tick_time->tm_min % 2;  // HACK
  if (graph_data)
    return graph_data->sun[graph_data->now] > 0;
  else
    return true;
}

static void update_time(struct tm* tick_time) {
  // Create a long-lived buffer
  static char time_buffer[] = "00:00";

  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(time_buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    // Use 12 hour format
    strftime(time_buffer, sizeof("00:00"), "%I:%M", tick_time);
  }

  // Display this time on the TextLayer
  text_layer_set_text(time_layer, time_buffer);
  
  // Now format and update the date (note: %e is padded to two chars, with a leading space)
  static char date_buffer[] = " 7 Saturday";  // Note: this should be more than enough for any conceivable locale
  strftime(date_buffer, sizeof(" 7 Saturday"), "%e %a", tick_time);
  text_layer_set_text(date_layer, date_buffer);
}

static void update_moon(struct tm* tick_time) {
  float dayFrac = (tick_time->tm_hour*60 + tick_time->tm_min)/(24*60.0f);
  float hourFrac = tick_time->tm_min/60.0f;
  // New moon every hour:
  float phase = hourFrac;
  // Rotate through 180 degrees each day (including from 45 left in the morning to 45 right in the evening):
  float rotation = (dayFrac - 0.5f)/2;
  
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "phase: %d", (int16_t) (phase*100));
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "hour: %d", (int16_t) tick_time->tm_hour);
  
  pm_moon_render(moon_bitmap, phase, rotation, is_day(tick_time));
  
  if (moon_layer != NULL) layer_mark_dirty((Layer *) moon_layer);

  APP_LOG(APP_LOG_LEVEL_DEBUG, "doner");
}

static void update_graph_data(struct tm *tick_time) {
  // Scale the current time to a 144-point scale where 6am/pm are always at the 
  // left and right edges:
  graph_data->now = ((tick_time->tm_hour+6) % 12)*12 + tick_time->tm_min/5;

  // update the sun and moon positions
  // TODO: only twice/day?

  // graph_data->baseHour = 6;
  // graph_data->baseHour = tick_time->tm_hour;
  if (tick_time->tm_hour < 6) graph_data->baseHour = -6;
  else if (tick_time->tm_hour >= 18) graph_data->baseHour = 18;
  else graph_data->baseHour = 6;
  
  for (int32_t tick = 0; tick < 144; tick += 1) {
    float almanac = almanac_time((int32_t) tick_time->tm_year + 1900,
      tick_time->tm_yday,
      graph_data->baseHour,
      tick*5 + 420);  // HACK
    // APP_LOG(APP_LOG_LEVEL_DEBUG, "almanac:   %d..%ld", (int16_t) almanac, (int32_t) (almanac*10000));
    float sun_elev = sun_elevation(almanac, 40, -105, graph_data->baseHour + (tick*5)/60.0);
    graph_data->sun[tick] = sun_elev;
  }
}
  
static void update_graph(struct tm *tick_time) {
  layer_mark_dirty(graph_layer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
//   float almanac_f = almanac_time_f(
//     (int32_t) tick_time->tm_year + 1900,
//     tick_time->tm_yday,
//     tick_time->tm_hour,
//     tick_time->tm_min + 420);  // HACK
//   APP_LOG(APP_LOG_LEVEL_DEBUG, "almanac_f: %d..%ld", (int16_t) almanac_f, (int32_t) (almanac_f*10000));
  
//   double almanac = almanac_time(
//     (int32_t) tick_time->tm_year + 1900,
//     tick_time->tm_yday,
//     tick_time->tm_hour,
//     tick_time->tm_min + 420);  // HACK
//   APP_LOG(APP_LOG_LEVEL_DEBUG, "almanac:   %d..%ld", (int16_t) almanac, (int32_t) (almanac*10000));
  
//   float elNow = sun_elevation(almanac, 40, -105, tick_time->tm_hour);
//   APP_LOG(APP_LOG_LEVEL_DEBUG, "elevation now(x1000):  %ld", (int32_t) (elNow*1000));
  
//   double almanacNoon = almanac_time(
//     (int32_t) tick_time->tm_year + 1900,
//     tick_time->tm_yday,
//     12,
//     tick_time->tm_min + 420);  // HACK
//   float elNoon = sun_elevation(almanacNoon, 40, -105, 12);
//   APP_LOG(APP_LOG_LEVEL_DEBUG, "elevation noon(x1000): %ld", (int32_t) (elNoon*1000));
  
  // HACK
//   tick_time->tm_hour -= 8;
  
  update_graph_data(tick_time);
  set_day_night_mode(is_day(tick_time));

  update_time(tick_time);
  update_moon(tick_time);
  update_graph(tick_time);
}

int32_t __errno; // HACK

static void init(void) {
  pm_sync_init();
  
  init_moon();
  
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  update_moon(tick_time);

  window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  const bool animated = true;
  window_stack_push(window, animated);
  
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  
  update_time(tick_time);
}


static void deinit(void) {
  window_destroy(window);
  
  pm_sync_deinit();
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  // APP_LOG(APP_LOG_LEVEL_DEBUG, "Pixel (10, 20) is: %d", getMoonPixel(10, 20));

  app_event_loop();

  deinit();
}
