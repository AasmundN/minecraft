#include "color.h"

#include <SDL.h>
#include <stdio.h>

/*
 * Colors hex values
 */
char color[][8] = {"#aa0bff", "#000000"};

void setRenderColor(App *app, const char *color) {
  char r[3];
  char g[3];
  char b[3];

  strncpy(r, color + 1, 2);
  strncpy(g, color + 3, 2);
  strncpy(b, color + 5, 2);

  SDL_SetRenderDrawColor(app->renderer, strtol(r, NULL, 16), strtol(g, NULL, 16), strtol(b, NULL, 16), 0xff);
}
