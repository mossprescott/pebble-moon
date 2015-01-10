#include "graph.h"

#define BASELINE (GRAPH_HEIGHT/2)
#define SUN_RADIUS 2

static int16_t toY(float value) {
  return BASELINE*(1.0 - value);
}

void render_graph(GContext* ctx, GraphData *data) {
  graphics_context_set_stroke_color(ctx, data->foreground);
  
  graphics_draw_line(ctx,
    (GPoint) { .x = 0, .y = BASELINE },
    (GPoint) { .x = 144, .y = BASELINE });

  for (int i=0; i < 12; i++) {
    if (i % 3 == 0) {
      graphics_draw_rect(ctx, (GRect) {
        .origin = { i*12 - 1, BASELINE },
        .size = { 2, 5 } });
    }
    else {
      graphics_draw_line(ctx,
        (GPoint) { .x = i*12, .y = BASELINE },
        (GPoint) { .x = i*12, .y = BASELINE + 3 });
    }
  }

  // Plot sun, showing every pixel:
  for (int i=0; i < 144; i += 1) {
    float val = data->sun[i];
    if (val != NO_DATA) {
      graphics_draw_pixel(ctx, (GPoint) { .x = i, .y = toY(val) });
    }
  }

  // Plot moon, drawing only every other pixel:
  for (int i=0; i < 144; i += 2) {
    float val = data->moon[i];
    if (val != NO_DATA) {
      graphics_draw_pixel(ctx, (GPoint) { .x = i, .y = toY(val) });
    }
  }
  
  // Draw the sun itself and an indicator line at the current time:
  float sun_val = data->sun[data->now];
  if (sun_val != NO_DATA && sun_val >= 0.0) {
    int16_t sunX = data->now;
    int16_t sunY = BASELINE*(1.0 - sun_val);

    // A line to the time axis:
    graphics_draw_line(ctx,
      (GPoint) { .x = data->now, .y = sunY },
      (GPoint) { .x = data->now, .y = BASELINE });

    // Some pixels lamely suggesting rays every 60 degrees:
    graphics_draw_pixel(ctx, (GPoint) { .x = sunX, .y = sunY - (SUN_RADIUS + 2) });
    graphics_draw_pixel(ctx, (GPoint) { .x = sunX + (SUN_RADIUS + 2), .y = sunY - SUN_RADIUS });
    graphics_draw_pixel(ctx, (GPoint) { .x = sunX - (SUN_RADIUS + 2), .y = sunY - SUN_RADIUS });
    graphics_draw_pixel(ctx, (GPoint) { .x = sunX + (SUN_RADIUS + 2), .y = sunY + SUN_RADIUS });
    graphics_draw_pixel(ctx, (GPoint) { .x = sunX - (SUN_RADIUS + 2), .y = sunY + SUN_RADIUS });

    // The sun's disk:
    graphics_context_set_fill_color(ctx, data->background);
    graphics_context_set_stroke_color(ctx, data->foreground);
    graphics_fill_circle(ctx, (GPoint) { .x = sunX, .y = sunY }, SUN_RADIUS);
    graphics_draw_circle(ctx, (GPoint) { .x = sunX, .y = sunY }, SUN_RADIUS);
  }
  else {
    // When the sun is below the horizon, still show an indicator line:
    graphics_draw_line(ctx,
      (GPoint) { .x = data->now, .y = BASELINE - 4 },
      (GPoint) { .x = data->now, .y = BASELINE });
  }
}