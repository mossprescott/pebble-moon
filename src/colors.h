#include <pebble.h>

#ifdef PBL_COLOR

#define UI_FG(isDay)  (isDay ? GColorBlack        : GColorRed)
#define UI_BG(isDay)  (isDay ? GColorCeleste      : GColorBlack)

#define SUN_FG(isDay) (isDay ? GColorChromeYellow : GColorPastelYellow)
// TODO: additional color(s) for anti-aliasing

#else

#define __on(isDay) (isDay ? GColorBlack : GColorWhite)
#define __off(isDay) __on(!isDay)

#define UI_FG __on
#define UI_BG __off

#define SUN_FG __on

#endif
