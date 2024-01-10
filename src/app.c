#include "app.h"
#include "block.h"
#include "color.h"

#include <SDL.h>
#include <math.h>
#include <matrix.h>
#include <stdbool.h>
#include <stdio.h>

void initSDL(App *app, int width, int height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &app->window, &app->renderer);

  SDL_SetWindowTitle(app->window, "Voxel engine");

  // SDL_SetRelativeMouseMode(SDL_TRUE);
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

void toggleRelativeMouseMode() {
  SDL_bool state = SDL_GetRelativeMouseMode();
  SDL_SetRelativeMouseMode(!state);
}

void handleKeyDown(App *app, SDL_KeyboardEvent *event) {
  switch (event->keysym.sym) {
  case SDLK_w:
    app->player.movementDirections[FORWARD] = true;
    break;

  case SDLK_s:
    app->player.movementDirections[BACKWARD] = true;
    break;

  case SDLK_LSHIFT:
    app->player.movementDirections[DOWN] = true;
    break;

  case SDLK_SPACE:
    app->player.movementDirections[UP] = true;
    break;

  case SDLK_ESCAPE:
    app->state = STOPPED;
    break;

  case SDLK_LCTRL:
    toggleRelativeMouseMode();
    break;
  }
}

void handleKeyUp(App *app, SDL_KeyboardEvent *event) {
  switch (event->keysym.sym) {
  case SDLK_w:
    app->player.movementDirections[FORWARD] = false;
    break;

  case SDLK_s:
    app->player.movementDirections[BACKWARD] = false;
    break;

  case SDLK_LSHIFT:
    app->player.movementDirections[DOWN] = false;
    break;

  case SDLK_SPACE:
    app->player.movementDirections[UP] = false;
    break;
  }
}

void handleMouseMotion(App *app, SDL_MouseMotionEvent *event) {
  app->player.orientation.angleX += event->yrel / 3;
  app->player.orientation.angleY -= event->xrel / 3;
}

void handleEvents(App *app) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      app->state = STOPPED;
      break;

    case SDL_KEYDOWN:
      handleKeyDown(app, &event.key);
      break;
    case SDL_KEYUP:
      handleKeyUp(app, &event.key);
      break;

    case SDL_MOUSEMOTION:
      // handleMouseMotion(app, &event.motion);
      break;
    }
  }
}

void clearFrame(App *app) {
  setRenderColor(app, color[RED]);
  SDL_RenderClear(app->renderer);
}

void moveForward(Player *player) {
  const float angleRad = degreesToRad(player->orientation.angleY);
  player->x -= MOVE_SPEED * sin(angleRad);
  player->z -= MOVE_SPEED * cos(angleRad);
}

void movePlayer(App *app) {
  if (app->player.movementDirections[FORWARD]) app->player.z -= MOVE_SPEED;
  if (app->player.movementDirections[BACKWARD]) app->player.z += MOVE_SPEED;
}

void drawFrame(App *app) {
  // some temporary blocks for demonstration
  Block block = {GRASS, {0, 1, 0}};
  renderBlock(app, &block);

  SDL_RenderPresent(app->renderer);
}