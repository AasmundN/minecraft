#ifndef APP_H
#define APP_H

#include <stdbool.h>

#define MOVE_SPEED 1

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

/*
 * Orientation in three dimenasions
 */
typedef struct {
  float angleX, angleY, angleZ;
} Orientation;

typedef enum {
  UP,
  DOWN,
  FORWARD,
  BACKWARD,
  RIGHT,
  LEFT
} Direction;

/*
 * Player struct
 */
typedef struct {
  Orientation orientation;
  bool movementDirections[6];
  float x, y, z;
} Player;

typedef struct {
  struct SDL_Renderer *renderer;
  struct SDL_Window *window;
  State state;
  int width, height;
  Player player;
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
 * Move player
 */
void movePlayer(App *app);

/*
 * Draw new frame
 */
void drawFrame(App *app);

#endif