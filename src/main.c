#include "app.h"
#include "block.h"

#include <SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FPS 30

int main(int argc, char *argv[]) {
  /*
   * Create app instance
   */
  App app = {NULL, NULL, RUNNING, WINDOW_WIDTH, WINDOW_HEIGHT};

  initSDL(&app, WINDOW_WIDTH, WINDOW_HEIGHT);

  /*
   * App loop
   */
  while (app.state == RUNNING) {
    float frameStart = SDL_GetTicks();

    SDL_GetWindowSize(app.window, &app.width, &app.height);

    app.player.orientation.angleX += 1;
    app.player.orientation.angleY += 2;

    handleEvents(&app);

    clearFrame(&app);

    movePlayer(&app);

    drawFrame(&app);

    // wait for next frame
    float frameTime = SDL_GetTicks() - frameStart;
    if (1000 / FPS > frameTime) {
      SDL_Delay(1000 / FPS - frameTime);
    }
  }

  cleanup(&app);

  return 0;
}
