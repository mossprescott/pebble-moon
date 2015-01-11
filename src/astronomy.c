#include "astronomy.h"

// See http://stackoverflow.com/a/8764866

float almanac_time(struct tm* time, int16_t offset_minutes) {
  int32_t day = time->tm_yday + 1;
  
  int32_t delta = time->tm_year - 49;
  int32_t leap = delta/4;  // Note: truncates
  float frac = time->tm_hour/24.0 + ((int32_t) time->tm_min + offset_minutes)/(24*60.0);
  float jd = 32916.5 + delta*365 + leap + day + frac;

  // APP_LOG(APP_LOG_LEVEL_DEBUG, "day: %ld", day);
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "delta: %ld", delta);
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "leap: %ld", leap);
  
  return jd - 51545.0;
}