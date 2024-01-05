#include "app.h"
#include "block.h"
#include "color.h"

#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

void initSDL(App *app, int width, int height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_CreateWindowAndRenderer(width, height, 0, &app->window, &app->renderer);
}

void cleanup(App *app) {
  if (app->renderer != NULL) {
    SDL_DestroyRenderer(app->renderer);
  }

  if (app->window != NULL) {
    SDL_DestroyWindow(app->window);
  }

  SDL_Quit();
}

void handleEvents(App *app) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      app->state = STOPPED;
      break;
    }
  }
}

void clearFrame(App *app) {
  setRenderColor(app, color[RED]);
  SDL_RenderClear(app->renderer);
}

void drawFrame(App *app) {
  // some temporary blocks for demonstration
  Block block = {GRASS, {0, 0, 0}};
  renderBlock(app, &block);

  Block block2 = {GRASS, {2, 3, 0}};
  renderBlock(app, &block2);

  SDL_RenderPresent(app->renderer);
}