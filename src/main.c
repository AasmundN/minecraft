#include "app.h"
#include "block.h"

#include <SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FPS 60

int main(int argc, char *argv[])
{
  /*
   * Create app instance
   */
  struct App *app = initApp(WINDOW_WIDTH, WINDOW_HEIGHT);

  struct Block block = {GRASS, {0, 0, 0}};
  struct Block block2 = {GRASS, {1, 1, -1}};
  struct Block block3 = {GRASS, {1, 3, 0}};
  struct Block block4 = {GRASS, {1, 3, 2}};
  struct Block block5 = {GRASS, {4, 1, 0}};

  addBlock(app, &block);
  addBlock(app, &block2);
  addBlock(app, &block3);
  addBlock(app, &block4);
  addBlock(app, &block5);

  /*
   * App loop
   */
  while (app->state == RUNNING)
  {
    float frameStart = SDL_GetTicks();

    SDL_GetWindowSize(app->window, &app->width, &app->height);

    app->player.orientation.angleX += 1;
    app->player.orientation.angleY += 2;

    handleEvents(app);

    clearFrame(app);

    movePlayer(app);

    renderFrame(app);

    // wait for next frame
    float frameTime = SDL_GetTicks() - frameStart;
    if (1000 / FPS > frameTime)
    {
      SDL_Delay(1000 / FPS - frameTime);
    }
  }

  destroyApp(app);

  return 0;
}
