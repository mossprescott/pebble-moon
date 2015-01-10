#include <pebble.h>

// Number of days since 1 Jan. 2000, as of the current time
// Note: 5 Jan. 2015 => 5483 
float almanac_time(struct tm* time, int16_t offset_minutes);