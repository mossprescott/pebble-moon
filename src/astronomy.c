// #include <math.h>
#include "astronomy.h"
#define USE_FIXED_POINT 1
#include "math-sll.h"

// See http://stackoverflow.com/a/8764866

// float almanac_time(struct tm* time, int16_t offset_minutes) {
//   int32_t day = time->tm_yday + 1;
//
//   int32_t delta = time->tm_year - 49;
//   int32_t leap = delta/4;  // Note: truncates
//   float frac = time->tm_hour/24.0 + ((int32_t) time->tm_min + offset_minutes)/(24*60.0);
//   float jd = 32916.5 + delta*365 + leap + day + frac;
//
//   // APP_LOG(APP_LOG_LEVEL_DEBUG, "day: %ld", day);
//   // APP_LOG(APP_LOG_LEVEL_DEBUG, "delta: %ld", delta);
//   // APP_LOG(APP_LOG_LEVEL_DEBUG, "leap: %ld", leap);
//
//   return jd - 51545.0;
// }

float almanac_time_f(int32_t year, int32_t day, int32_t hour, int32_t minute) {
  int32_t delta = year - 1949;
  int32_t leap = delta/4;  // Note: truncates
  float frac = (hour*60 + minute)/MINUTES_PER_DAY;
  float jd = 32916.5 + delta*365 + leap + day+1 + frac;
  return jd - 51545;
}

// Resolution of (32-bit) float seems to be about 5 minutes, since 
// 5480*1440 ~= 2^23. Doubles might be very slow, in which case 
// 31.32 fixed point is an option.
double almanac_time(int32_t year, int32_t day, int32_t hour, int32_t minute) {
  int32_t delta = year - 1949;
  int32_t leap = delta/4;  // Note: truncates
  double frac = (hour*60 + minute)/((double) MINUTES_PER_DAY);
  double jd = 32916.5 + delta*365 + leap + day+1 + frac;
  return jd - 51545;
}

// sin and cos, for floats, using sin/cos_lookup
// angle: 1.0f == 2*π
// HACK: copied from moon.c
static float sin_f(float angle) {
  return ((float) sin_lookup((int32_t) (angle*TRIG_MAX_ANGLE)))/TRIG_MAX_RATIO;
}
static float cos_f(float angle) {
  return ((float) cos_lookup((int32_t) (angle*TRIG_MAX_ANGLE)))/TRIG_MAX_RATIO;
}
static float atan2_f(float x, float y) {
  return ((float) atan2_lookup((int32_t) (x * TRIG_MAX_RATIO), (int32_t) (y * TRIG_MAX_RATIO)))/TRIG_MAX_ANGLE;
}
static sll sllasin(sll y) {
  sll x = sllsqrt(1 - sllmul(y, y));
  return sllmul2(sllatan(slldiv(y, slladd(CONST_1, x))));
}
static float asin_f(float y) {
  // float x = sll2dbl(sllsqrt(dbl2sll(1 - y*y)));
  // return 2*atan2_f(y, 1 + x);
  
  return sll2dbl(sllasin(dbl2sll(y)));
}
static float deg2pebble(float deg) {
  return deg/360;
}
static float mod(double x, double y) {
  // double rem = fmod(x, y);
  // if (rem < 0) return rem + y;
  // else return rem;
  sll sx = dbl2sll(x);
  sll sy = dbl2sll(y);
  
  sll tquot = sllint(slldiv(sx, sy));
  sll rem = sllsub(sx, sllmul(tquot, sy));
  if (rem < 0) rem = slladd(rem, sy);
  return sll2dbl(rem);
}

static sll pebble2rad(float x) {
  return sllmul(dbl2sll(x), CONST_2_PI);
}

static float rad2pebble(sll x) {
  return sll2dbl(slldiv(x, CONST_2_PI));
}

float sun_elevation(double almanac, float latDeg, float longDeg, float hour) {
  // return mod(almanac, 1); // HACK
  
  // Mean longitude and anomaly:
  float mnLongDeg = mod(280.460 + 0.9856474*almanac, 360);
  float mnAnomDeg = mod(375.528 + 0.9856003*almanac, 360);
  
  // Ecliptic longitude and obliquity of ecliptic:
  float ecLongDeg = mod(mnLongDeg + 1.915*sin_f(deg2pebble(mnAnomDeg)) + 0.020*sin_f(2*deg2pebble(mnAnomDeg)), 360);
  float oblqEcDeg = mod(23.439 - 0.0000004*almanac, 360);

  // Celestial coordinates (right ascension and declination):
  float num = cos_f(deg2pebble(oblqEcDeg)) * sin_f(deg2pebble(ecLongDeg));
  float den = cos_f(deg2pebble(ecLongDeg));
  float rightAsc = atan2_f(num, den);
  if (den < 0)      rightAsc += 0.5;
  else if (num < 0) rightAsc += 1.0;
  float dec = asin_f(sin_f(deg2pebble(oblqEcDeg)) * sin_f(deg2pebble(ecLongDeg)));

  // Greenwich mean sidereal time:
  float gmstHrs = mod(6.697375 + 0.0657098242*almanac + hour, 24);
  
  // Local mean sidereal time:
  float lmstDeg = mod(gmstHrs + longDeg/15, 24)*15;

  // Hour angle:
  float hourAngle = mod(deg2pebble(lmstDeg) - rightAsc, 1);
  // if (hourAngle > 1) hourAngle -= 2;
  // float hourAngle = deg2pebble(lmstDeg) - rightAsc;

  // return cos_f(hourAngle); // HACK
  // return sin_f(dec); // HACK: 0, then -1 from 17:00
  // return sin_f(deg2pebble(latDeg)); // HACK: flat at ~1
  // return mnLongDeg/360; // 1
  // return mnAnomDeg/360; // 0.1
  // return ecLongDeg/360; // 1
  // return oblqEcDeg/360;

  // Elevation:
  float elevation = 
//     cos_f(deg2pebble(hour*15));
    // asin_f(cos_f(deg2pebble(hour*15)))/2;

    // skip asin, since sin is already the height anyway, right?
    // asin_f(
//     (sin_f(dec) * sin_f(deg2pebble(latDeg))) +
//     (cos_f(dec) * cos_f(deg2pebble(latDeg)) * cos_f(hourAngle));
    cos_f(deg2pebble(latDeg)) * cos_f(hourAngle);
    
    // (sin_f(dec) * sin_f(deg2pebble(latDeg))) +
    // (cos_f(dec) * cos_f(deg2pebble(latDeg)) * cos_f(hourAngle)));
  
  // horribly broken:
  // float elevation = asin_f(rad2pebble(
  //   (sllsin(pebble2rad(dec)) * sllsin(pebble2rad(deg2pebble(latitude)))) +
  //   (sllcos(pebble2rad(dec)) * sllcos(pebble2rad(deg2pebble(latitude))) * sllcos(pebble2rad(hourAngle)))));

  return elevation;
}