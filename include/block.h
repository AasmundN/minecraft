#ifndef BLOCK_H
#define BLOCK_H

#include "app.h"

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
typedef struct {
  Block_t type;
  Vector3d pos;
} Block;

/*
 * Find faces, and their vertices, of a cube
 * block: block to be calculated
 * faces: pointer to array where the faces are to be stored
 */
void getFaces(Block *block, Face *faces);

/*
 * */
void renderBlock(App *app, Block *block);

#endif