#include "block.h"
#include "app.h"
#include "matrix.h"

#include <SDL.h>

void getFaces(struct Block *block, Face *faces) {
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

/*
 * Add quad (face) to a list of quads
 */
void addQuad(Frame *frame, Face *quad) {
  frame->quads = realloc(frame->quads, (frame->numQuads + 1) * sizeof(Face));

  memcpy(&frame->quads[frame->numQuads], quad, sizeof(Face));

  frame->numQuads++;
}

void projectFace(struct App *app, Frame *frame, Face *face, int index) {
  Face quad;

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

    duplicateVector(&projectedVertex, &quad.vertices[i]);
  }

  Vector3d a, b, faceNormal;

  vectorSubtract(&quad.vertices[1], &quad.vertices[0], &a);
  vectorSubtract(&quad.vertices[3], &quad.vertices[0], &b);

  vectorCrossProduct(&a, &b, &faceNormal);

  /*
   * Only render faces we can actually see
   */
  if (vectorDotProduct(&faceNormal, &quad.vertices[0]) > 0) return;

  addQuad(frame, &quad);
}

void projectBlock(struct App *app, Frame *frame, struct Block *block) {
  Face *faces = malloc(6 * sizeof(Face));
  getFaces(block, faces);

  for (int i = 0; i < 6; i++)
    projectFace(app, frame, faces + i, i);

  free(faces);
}

void renderQuad(struct App *app, Face *quad) {
  SDL_Vertex vertices[4];

  for (int i = 0; i < 4; i++) {

    // temporary set color of face
    vertices[i].color.r = 0x55;
    vertices[i].color.g = 0x00;
    vertices[i].color.b = 0x00;
    vertices[i].color.a = 0xff;

    vertices[i].position.x = quad->vertices[i].x;
    vertices[i].position.y = quad->vertices[i].y;

    /*
     * Scale projected vertex to screen
     */
    vertices[i].position.x += 1;
    vertices[i].position.y += 1;
    vertices[i].position.x *= 0.5 * app->width;
    vertices[i].position.y *= 0.5 * app->height;
  }

  /*
   * Vertex rendering order
   * This will produce a square
   */
  const int indices[] = {0, 1, 3, 3, 1, 2};

  // SDL_RenderGeometry(app->renderer, NULL, vertices, 4, indices, 6);
  drawWireFrame(app->renderer, vertices);
}

void drawFrame(struct App *app) {
  Frame *frame = malloc(sizeof(Frame));

  frame->quads = malloc(0);
  frame->numQuads = 0;

  for (int i = 0; i < app->numBlocks; i++)
    projectBlock(app, frame, &app->blocks[i]);

  for (int i = 0; i < frame->numQuads; i++)
    renderQuad(app, &frame->quads[i]);

  free(frame->quads);
  free(frame);
}
