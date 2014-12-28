#include <pebble.h>
#include "moon.h"
#include "sync.h"

static Window *window;
static TextLayer *time_layer;
static GBitmap *moon_bitmap;
static BitmapLayer *moon_layer;

static void init_moon() {
  int size = 144;
  moon_bitmap = gbitmap_create_blank((GSize) { .w = size, .h = size });
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  time_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { bounds.size.w, 20 } });
  text_layer_set_text(time_layer, "12:34");
  text_layer_set_text_alignment(time_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(time_layer));
  
  uint16_t size = moon_bitmap->bounds.size.w;
  moon_layer = bitmap_layer_create((GRect) { 
    .origin = { bounds.size.w/2 - size/2, 20 + (bounds.size.h - 20)/2 - size/2 },
    .size = moon_bitmap->bounds.size });
  bitmap_layer_set_bitmap(moon_layer, moon_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(moon_layer));
}

static void window_unload(Window *window) {
  text_layer_destroy(time_layer);
  
  gbitmap_destroy((GBitmap *) bitmap_layer_get_bitmap(moon_layer));
  bitmap_layer_destroy(moon_layer);
}

static void update_time(struct tm* tick_time) {
  // Create a long-lived buffer
  static char buffer[] = "00:00";

  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    // Use 12 hour format
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
  }

  // Display this time on the TextLayer
  text_layer_set_text(time_layer, buffer);
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
  
  pm_moon_render(moon_bitmap, phase, rotation);
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "doner");
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time(tick_time);
  update_moon(tick_time);
  layer_mark_dirty((Layer *) moon_layer);
}

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
