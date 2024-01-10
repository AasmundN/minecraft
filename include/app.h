#ifndef APP_H
#define APP_H

#include <stdbool.h>

#include "block.h"

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
struct Player {
  Orientation orientation;
  bool movementDirections[6];
  float x, y, z;
};

struct App {
  struct SDL_Renderer *renderer;
  struct SDL_Window *window;
  int width, height;

  State state;

  struct Player player;

  struct Block *blocks;
  int numBlocks;
};

/*
 * Init application struct with specified window width and height
 */
struct App *initApp(int width, int height);

/*
 * Free app resources
 */
void destroyApp(struct App *app);

/*
 * Add block to app block list
 */
void addBlock(struct App *app, struct Block *block);

/*
 * Handle SDL events
 */
void handleEvents(struct App *app);

/*
 * Clear renderer
 */
void clearFrame(struct App *app);

/*
 * Move player
 */
void movePlayer(struct App *app);

/*
 * Draw new frame
 */
void renderFrame(struct App *app);

#endif