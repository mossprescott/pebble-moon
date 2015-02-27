#include <pebble.h>

#define GRAPH_HEIGHT 48

typedef struct {
  // Index of the current time, from 0 to 143:
  int16_t now;
  
  // Hour at the left edge of the graph, 0-23 (although actually negative values are also used):
  int16_t baseHour;

  bool isDay;
  
  float sun[144];
  float moon[144];
} GraphData;


#define NO_DATA -1.0f



void render_graph(GContext* ctx, GraphData *data);