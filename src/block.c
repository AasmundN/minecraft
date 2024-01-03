#include "block.h"
#include "matrix.h"

#include <SDL.h>

void getFaces(Block *block, Face *faces) {
  /*
   * Front face
   */

  faces[FRONT].vertices[0].x = block->pos.x * BLOCK_SIZE;
  faces[FRONT].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[FRONT].vertices[0].z = block->pos.z * BLOCK_SIZE;

  faces[FRONT].vertices[1].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[FRONT].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[FRONT].vertices[1].z = block->pos.z * BLOCK_SIZE;

  faces[FRONT].vertices[2].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[FRONT].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[FRONT].vertices[2].z = block->pos.z * BLOCK_SIZE;

  faces[FRONT].vertices[3].x = block->pos.x * BLOCK_SIZE;
  faces[FRONT].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[FRONT].vertices[3].z = block->pos.z * BLOCK_SIZE;

  /*
   * Right face
   */

  faces[RIGHT].vertices[0].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT].vertices[0].z = block->pos.z * BLOCK_SIZE;

  faces[RIGHT].vertices[1].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT].vertices[1].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[RIGHT].vertices[2].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[RIGHT].vertices[2].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[RIGHT].vertices[3].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[RIGHT].vertices[3].z = block->pos.z * BLOCK_SIZE;

  /*
   * Back face
   */

  faces[BACK].vertices[0].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[BACK].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[BACK].vertices[0].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[BACK].vertices[1].x = block->pos.x * BLOCK_SIZE;
  faces[BACK].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[BACK].vertices[1].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[BACK].vertices[2].x = block->pos.x * BLOCK_SIZE;
  faces[BACK].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[BACK].vertices[2].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[BACK].vertices[3].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[BACK].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[BACK].vertices[3].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  /*
   * Left face
   */

  faces[LEFT].vertices[0].x = block->pos.x * BLOCK_SIZE;
  faces[LEFT].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[LEFT].vertices[0].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[LEFT].vertices[1].x = block->pos.x * BLOCK_SIZE;
  faces[LEFT].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[LEFT].vertices[1].z = block->pos.z * BLOCK_SIZE;

  faces[LEFT].vertices[2].x = block->pos.x * BLOCK_SIZE;
  faces[LEFT].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[LEFT].vertices[2].z = block->pos.z * BLOCK_SIZE;

  faces[LEFT].vertices[3].x = block->pos.x * BLOCK_SIZE;
  faces[LEFT].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[LEFT].vertices[3].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  /*
   * Top face
   */

  faces[TOP].vertices[0].x = block->pos.x * BLOCK_SIZE;
  faces[TOP].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP].vertices[0].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[TOP].vertices[1].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP].vertices[1].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[TOP].vertices[2].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP].vertices[2].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP].vertices[2].z = block->pos.z * BLOCK_SIZE;

  faces[TOP].vertices[3].x = block->pos.x * BLOCK_SIZE;
  faces[TOP].vertices[3].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP].vertices[3].z = block->pos.z * BLOCK_SIZE;

  /*
   * Bottom face
   */

  faces[BOTTOM].vertices[0].x = block->pos.x * BLOCK_SIZE;
  faces[BOTTOM].vertices[0].y = block->pos.y * BLOCK_SIZE;
  faces[BOTTOM].vertices[0].z = block->pos.z * BLOCK_SIZE;

  faces[BOTTOM].vertices[1].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[BOTTOM].vertices[1].y = block->pos.y * BLOCK_SIZE;
  faces[BOTTOM].vertices[1].z = block->pos.z * BLOCK_SIZE;

  faces[BOTTOM].vertices[2].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[BOTTOM].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[BOTTOM].vertices[2].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[BOTTOM].vertices[3].x = block->pos.x * BLOCK_SIZE;
  faces[BOTTOM].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[BOTTOM].vertices[3].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;
}

void renderBlock(App *app, Block *block) {
  Face *faces = malloc(6 * sizeof(Face));
  getFaces(block, faces);

  for (int i = 0; i < 6; i++)
    renderFace(app, faces + i, i);

  free(faces);
}

void renderFace(App *app, Face *face, int index) {
  SDL_Vertex vertices[4];

  for (int i = 0; i < 4; i++) {
    Vertex rotatedX;
    Vertex rotatedY;

    Vertex projectedVertex;

    rotateX(&face->vertices[i], &rotatedX, app->angleX);
    rotateY(&rotatedX, &rotatedY, app->angleY);
    perspectiveTransform(&rotatedY, &projectedVertex, app->width, app->height);

    vertices[i].color.r = 30 + 20 * index;
    vertices[i].color.g = 0;
    vertices[i].color.b = 0;
    vertices[i].color.a = 0xff;

    vertices[i].position.x = projectedVertex.x + app->width / 2;
    vertices[i].position.y = -projectedVertex.y + app->height / 2;
  }

  const int indices[] = {0, 1, 3, 3, 1, 2};

  SDL_RenderGeometry(app->renderer, NULL, vertices, 4, indices, 6);
}