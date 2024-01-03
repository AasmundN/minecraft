#ifndef BLOCK_H
#define BLOCK_H

#include "app.h"

/*
 * Dimension of one block
 */
#define BLOCK_SIZE 50

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
  FRONT,
  RIGHT,
  BACK,
  LEFT,
  TOP,
  BOTTOM
} Face_t;

/*
 * Vertex position struct
 */
typedef struct {
  float x, y, z;
} Vertex;

/*
 *Face of block
 */
typedef struct {
  Vertex vertices[4];
} Face;

/*
 * Block position in chunk
 */
typedef struct {
  int x, y, z;
} ChunkPos;

/*
 * Block struct
 */
typedef struct {
  Block_t type;
  ChunkPos pos;
} Block;

/*
 * Find faces, and their vertices, of a cube
 * block: block to be calculated
 * faces: pointer to array where the faces are to be stored
 */
void getFaces(Block *block, Face *faces);

void renderBlock(App *app, Block *block);

void renderFace(App *app, Face *face, int index);

#endif