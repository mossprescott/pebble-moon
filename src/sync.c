#include <pebble.h>
#include "sync.h"

static AppSync s_sync;
static uint8_t s_sync_buffer[256];

// HACK: integer degrees means ~60 mi. resolution
int32_t latitude = 40;
int32_t longitude = -105;
int32_t offset_minutes = 7*60;
  
static void sync_changed_handler(const uint32_t key, const Tuple *new_tuple, const Tuple *old_tuple, void *context) {
  if (key == KEY_LAT && new_tuple->type == TUPLE_INT) {
    latitude = new_tuple->value->int32;
    APP_LOG(APP_LOG_LEVEL_DEBUG, "received latitude: %ld", latitude);
  }
  else if (key == KEY_LON && new_tuple->type == TUPLE_INT) {
    longitude = new_tuple->value->int32;
    APP_LOG(APP_LOG_LEVEL_DEBUG, "received longitude: %ld", longitude);
  }
  else if (key == KEY_TZ_OFFSET && new_tuple->type == TUPLE_INT) {
    offset_minutes = new_tuple->value->int32;
    APP_LOG(APP_LOG_LEVEL_DEBUG, "received offset: %ld", offset_minutes);
  }
  else {
    APP_LOG(APP_LOG_LEVEL_WARNING, "unexpected key: %ld; type: %d; length: %d", key, new_tuple->type, new_tuple->length);
  }
}

static void sync_error_handler(DictionaryResult dict_error, AppMessageResult app_message_error, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "sync error!");
}

void pm_sync_init() {
  // Setup AppSync
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());

  // Setup initial values
  Tuplet initial_values[] = {
    TupletInteger(KEY_LAT, latitude),
    TupletInteger(KEY_LON, longitude),
    TupletInteger(KEY_TZ_OFFSET, offset_minutes)
  };

  // Begin using AppSync
  app_sync_init(&s_sync, s_sync_buffer, sizeof(s_sync_buffer), initial_values, ARRAY_LENGTH(initial_values), sync_changed_handler, sync_error_handler, NULL);
}

void pm_sync_deinit() {
  app_sync_deinit(&s_sync);
}