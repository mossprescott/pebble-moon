#include <pebble.h>

#define GRAPH_HEIGHT 48

typedef struct {
  int16_t now; // index of the current time, from 0 to 143
  GColor foreground;
  GColor background;
  
  float sun[144];
  float moon[144];
} GraphData;


#define NO_DATA -1.0f



void render_graph(GContext* ctx, GraphData *data);