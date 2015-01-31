#include <pebble.h>


#define MINUTES_PER_DAY (24*60)

// (Fractional) number of days since noon, 1 Jan. 2000.
//   year: with century
//   day: zero-based day of year (Jan 1 => 0)
//   hour: 0-23
//   minute: 0-59 (not required to be in that range)
// Note: 5 Jan. 2015 => 5483
float almanac_time_f(int32_t year, int32_t day, int32_t hour, int32_t minute);
double almanac_time(int32_t year, int32_t day, int32_t hour, int32_t minute);

float sun_elevation(double almanac, float latitude, float longitude, float hour);