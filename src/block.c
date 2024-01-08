#include "block.h"
#include "matrix.h"

#include <SDL.h>

void getFaces(Block *block, Face *faces) {
  /*
   * FRONT_FACE face
   */

  faces[FRONT_FACE].vertices[0].x = block->pos.x * BLOCK_SIZE;
  faces[FRONT_FACE].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[FRONT_FACE].vertices[0].z = block->pos.z * BLOCK_SIZE;

  faces[FRONT_FACE].vertices[1].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[FRONT_FACE].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[FRONT_FACE].vertices[1].z = block->pos.z * BLOCK_SIZE;

  faces[FRONT_FACE].vertices[2].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[FRONT_FACE].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[FRONT_FACE].vertices[2].z = block->pos.z * BLOCK_SIZE;

  faces[FRONT_FACE].vertices[3].x = block->pos.x * BLOCK_SIZE;
  faces[FRONT_FACE].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[FRONT_FACE].vertices[3].z = block->pos.z * BLOCK_SIZE;

  /*
   * RIGHT_FACE face
   */

  faces[RIGHT_FACE].vertices[0].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT_FACE].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT_FACE].vertices[0].z = block->pos.z * BLOCK_SIZE;

  faces[RIGHT_FACE].vertices[1].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT_FACE].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT_FACE].vertices[1].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[RIGHT_FACE].vertices[2].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT_FACE].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[RIGHT_FACE].vertices[2].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[RIGHT_FACE].vertices[3].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[RIGHT_FACE].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[RIGHT_FACE].vertices[3].z = block->pos.z * BLOCK_SIZE;

  /*
   * BACK_FACE face
   */

  faces[BACK_FACE].vertices[0].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[BACK_FACE].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[BACK_FACE].vertices[0].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[BACK_FACE].vertices[1].x = block->pos.x * BLOCK_SIZE;
  faces[BACK_FACE].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[BACK_FACE].vertices[1].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[BACK_FACE].vertices[2].x = block->pos.x * BLOCK_SIZE;
  faces[BACK_FACE].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[BACK_FACE].vertices[2].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[BACK_FACE].vertices[3].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[BACK_FACE].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[BACK_FACE].vertices[3].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  /*
   * LEFT_FACE face
   */

  faces[LEFT_FACE].vertices[0].x = block->pos.x * BLOCK_SIZE;
  faces[LEFT_FACE].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[LEFT_FACE].vertices[0].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[LEFT_FACE].vertices[1].x = block->pos.x * BLOCK_SIZE;
  faces[LEFT_FACE].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[LEFT_FACE].vertices[1].z = block->pos.z * BLOCK_SIZE;

  faces[LEFT_FACE].vertices[2].x = block->pos.x * BLOCK_SIZE;
  faces[LEFT_FACE].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[LEFT_FACE].vertices[2].z = block->pos.z * BLOCK_SIZE;

  faces[LEFT_FACE].vertices[3].x = block->pos.x * BLOCK_SIZE;
  faces[LEFT_FACE].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[LEFT_FACE].vertices[3].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  /*
   * TOP_FACE face
   */

  faces[TOP_FACE].vertices[0].x = block->pos.x * BLOCK_SIZE;
  faces[TOP_FACE].vertices[0].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP_FACE].vertices[0].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[TOP_FACE].vertices[1].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP_FACE].vertices[1].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP_FACE].vertices[1].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[TOP_FACE].vertices[2].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP_FACE].vertices[2].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP_FACE].vertices[2].z = block->pos.z * BLOCK_SIZE;

  faces[TOP_FACE].vertices[3].x = block->pos.x * BLOCK_SIZE;
  faces[TOP_FACE].vertices[3].y = block->pos.y * BLOCK_SIZE + BLOCK_SIZE;
  faces[TOP_FACE].vertices[3].z = block->pos.z * BLOCK_SIZE;

  /*
   * BOTTOM_FACE face
   */

  faces[BOTTOM_FACE].vertices[0].x = block->pos.x * BLOCK_SIZE;
  faces[BOTTOM_FACE].vertices[0].y = block->pos.y * BLOCK_SIZE;
  faces[BOTTOM_FACE].vertices[0].z = block->pos.z * BLOCK_SIZE;

  faces[BOTTOM_FACE].vertices[1].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[BOTTOM_FACE].vertices[1].y = block->pos.y * BLOCK_SIZE;
  faces[BOTTOM_FACE].vertices[1].z = block->pos.z * BLOCK_SIZE;

  faces[BOTTOM_FACE].vertices[2].x = block->pos.x * BLOCK_SIZE + BLOCK_SIZE;
  faces[BOTTOM_FACE].vertices[2].y = block->pos.y * BLOCK_SIZE;
  faces[BOTTOM_FACE].vertices[2].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;

  faces[BOTTOM_FACE].vertices[3].x = block->pos.x * BLOCK_SIZE;
  faces[BOTTOM_FACE].vertices[3].y = block->pos.y * BLOCK_SIZE;
  faces[BOTTOM_FACE].vertices[3].z = block->pos.z * BLOCK_SIZE + BLOCK_SIZE;
}

/*
 * Draw wire frame outline of a cube face
 */
void drawWireFrame(SDL_Renderer *renderer, SDL_Vertex vertices[4]) {
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
  SDL_RenderDrawLine(renderer, vertices[0].position.x, vertices[0].position.y, vertices[1].position.x, vertices[1].position.y);
  SDL_RenderDrawLine(renderer, vertices[1].position.x, vertices[1].position.y, vertices[2].position.x, vertices[2].position.y);
  SDL_RenderDrawLine(renderer, vertices[2].position.x, vertices[2].position.y, vertices[3].position.x, vertices[3].position.y);
  SDL_RenderDrawLine(renderer, vertices[3].position.x, vertices[3].position.y, vertices[0].position.x, vertices[0].position.y);
}

void renderFace(App *app, Face *face, int index) {
  SDL_Vertex verticesProjected[4];
  Vector3d vertices[4];

  for (int i = 0; i < 4; i++) {
    // intermediates
    Vector3d rotatedVertex, translatedVertex, projectedVertex;

    // translate coordinate system so that we can see the rotation
    translatedVertex.x = face->vertices[i].x + app->player.x;
    translatedVertex.y = face->vertices[i].y + app->player.y;
    translatedVertex.z = face->vertices[i].z + app->player.z;

    // rotate vertex
    rotateVector(&translatedVertex, &rotatedVertex, &app->player.orientation);

    // temporary translate
    rotatedVertex.z += 150;

    perspectiveTransform(&rotatedVertex, &projectedVertex, app->width, app->height);

    // temporary set color of face
    verticesProjected[i].color.r = 80 + 5 * index;
    verticesProjected[i].color.g = 0;
    verticesProjected[i].color.b = 0;
    verticesProjected[i].color.a = 0xff;

    /*
     * Scale projected vertex to screen
     */
    projectedVertex.x += 1;
    projectedVertex.y += 1;
    projectedVertex.x *= 0.5 * app->width;
    projectedVertex.y *= 0.5 * app->height;

    verticesProjected[i].position.x = projectedVertex.x;
    verticesProjected[i].position.y = projectedVertex.y;

    /*
     * Save 3d vertices
     */
    duplicateVector(&rotatedVertex, &vertices[i]);
  }

  Vector3d a, b, faceNormal;

  vectorSubtract(&vertices[1], &vertices[0], &a);
  vectorSubtract(&vertices[3], &vertices[0], &b);

  vectorCrossProduct(&a, &b, &faceNormal);

  /*
   * Only render faces we can actually see
   */
  if (vectorDotProduct(&faceNormal, &vertices[0]) > 0) return;

  /*
   * Vertex rendering order
   * This will produce a square
   */
  const int indices[] = {0, 1, 3, 3, 1, 2};

  // SDL_RenderGeometry(app->renderer, NULL, verticesProjected, 4, indices, 6);
  drawWireFrame(app->renderer, verticesProjected);
}

void renderBlock(App *app, Block *block) {
  Face *faces = malloc(6 * sizeof(Face));
  getFaces(block, faces);

  for (int i = 0; i < 6; i++)
    renderFace(app, faces + i, i);

  free(faces);
}
