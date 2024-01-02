#include "app.h"

#include <SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 500

int main(int argc, char *argv[]) {
  /*
   * Create app instance
   */
  App *app;
  memset(app, 0, sizeof(App));
  app->state = RUNNING;

  initSDL(app, WINDOW_WIDTH, WINDOW_HEIGHT);

  /*
   * App loop
   */
  while (app->state == RUNNING) {
    handleEvents(app);
  }

  cleanup(app);

  return 0;
}
