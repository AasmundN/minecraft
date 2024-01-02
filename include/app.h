#ifndef APP_H
#define APP_H

#include <stdbool.h>

/*
 * Forward declaration of SDL structs
 */
struct SDL_Renderer;
struct SDL_Window;

/*
 * App state enum
 */
typedef enum {
  RUNNING,
  STOPPED
} State;

typedef struct {
  struct SDL_Renderer *renderer;
  struct SDL_Window *window;
  State state;
} App;

/*
 * Init SDL window and renderer
 * app: struct containing renderer and window pointers
 * width: width of window
 * height: height of window
 */
void initSDL(App *app, int width, int height);

/*
 * Cleanup resources from SDL
 */
void cleanup(App *app);

/*
 * Handle SDL events
 */
void handleEvents(App *app);

/*
 * Clear renderer
 */
void clearFrame(App *app);

/*
 * Draw new frame
 */
void drawFrame(App *app);

#endif