#ifndef BLOCK_H
#define BLOCK_H

struct App;

/*
 * Dimension of one block
 */
#define BLOCK_SIZE 10

/*
 * Axis directions
 */
typedef enum {
  x,
  y,
  z
} Axis;

/*
 * Block types
 */
typedef enum {
  GRASS,
  AIR
} Block_t;

/*
 * Face types
 */
typedef enum {
  FRONT_FACE,
  RIGHT_FACE,
  BACK_FACE,
  LEFT_FACE,
  TOP_FACE,
  BOTTOM_FACE
} Face_t;

/*
 * Vector3d position struct
 */
typedef struct {
  float x, y, z;
} Vector3d;

/*
 *Face of block
 */
typedef struct {
  Vector3d vertices[4];
} Face;

/*
 * Block struct
 */
struct Block {
  Block_t type;
  Vector3d pos;
};

/*
 * A frame consists of all the (projected) quads that are to be drawn on the screen
 */
typedef struct {
  Face *quads;
  int numQuads;
} Frame;

/*
 * Finds the faces of a block and projects them onto the screen
 * frame: destination of the resulting, projected, quads.
 */
void projectBlock(struct App *app, Frame *frame, struct Block *block);

/*
 * Draws a frame to the renderer
 */
void drawFrame(struct App *app);

#endif