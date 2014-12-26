#include <pebble.h>
#include "moon.h"
#include "sync.h"

static Window *window;
static TextLayer *time_layer;
static BitmapLayer *moon_layer;

// static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
//   text_layer_set_text(text_layer, "Select");
// }
//
// static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
//   text_layer_set_text(text_layer, "Up");
// }
//
// static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
//   text_layer_set_text(text_layer, "Down");
// }

// static void click_config_provider(void *context) {
//   window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
//   window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
//   window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
// }

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  time_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { bounds.size.w, 20 } });
  text_layer_set_text(time_layer, "12:34");
  text_layer_set_text_alignment(time_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(time_layer));
  
  int size = 72;
  GBitmap* moon_bitmap = gbitmap_create_blank((GSize) { .w = size, .h = size });
  
  moon_layer = bitmap_layer_create((GRect) { 
    .origin = { bounds.size.w/2 - size/2, bounds.size.h/2 - size/2 },
    .size = { size, size } });
  bitmap_layer_set_bitmap(moon_layer, moon_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(moon_layer));
}

static void window_unload(Window *window) {
  text_layer_destroy(time_layer);
  
  gbitmap_destroy((GBitmap *) bitmap_layer_get_bitmap(moon_layer));
  bitmap_layer_destroy(moon_layer);
}

static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

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

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
  
  const GBitmap* bitmap = bitmap_layer_get_bitmap(moon_layer);
  pm_moon_render(bitmap);
  layer_mark_dirty((Layer *) moon_layer);
}

static void init(void) {
  window = window_create();
  // window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
  
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  
  pm_sync_init();
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
