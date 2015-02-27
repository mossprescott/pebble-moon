#include <pebble.h>

#ifdef PBL_COLOR

#define DAY_BG    GColorCeleste
#define DAY_FG    GColorBlack
#define NIGHT_BG  GColorBlack
#define NIGHT_FG  GColorRed

#define SUN_DAY_FG GColorChromeYellow //GColorRajah
#define SUN_NIGHT_FG GColorPastelYellow

#else

#define DAY_BG    GColorWhite
#define DAY_FG    GColorBlack
#define NIGHT_BG  GColorBlack
#define NIGHT_FG  GColorWhite

#define SUN_DAY_FG GColorBlack
#define SUN_NIGHT_FG GColorWhite

#endif
