#include "matrix.h"

#include <math.h>

#define PI 3.14159
#define FAR_PLANE 10000

float degreesToRad(float degrees) {
  return (PI * degrees) / 180;
}

void perspectiveTransform(Vertex *input, Vertex *output, int width, int height) {
  /*
   * Define constants
   */
  const float FOV = 50;
  const float aspectRatio = (float)width / (float)height;
  const float a = tan(degreesToRad(FOV / 2));
  const float w = 1;

  /*
   * Calculate near clipping plane distance
   */
  const float n = (float)height / (2 * a);

  /*
   * Define perspective projection matrix
   */
  const float perspectiveMatrix[4][4] = {
      {1 / (aspectRatio * a), 0, 0, 0},
      {0, 1 / a, 0, 0},
      {0, 0, FAR_PLANE / (FAR_PLANE - n), -FAR_PLANE * n / (FAR_PLANE - n)},
      {0, 0, 1, 0},
  };

  /*
   * Perform matrix multiplication
   */
  output->x = perspectiveMatrix[0][0] * input->x + perspectiveMatrix[0][1] * input->y + perspectiveMatrix[0][2] * input->z + perspectiveMatrix[0][3] * w;
  output->y = perspectiveMatrix[1][0] * input->x + perspectiveMatrix[1][1] * input->y + perspectiveMatrix[1][2] * input->z + perspectiveMatrix[1][3] * w;
  output->z = perspectiveMatrix[2][0] * input->x + perspectiveMatrix[2][1] * input->y + perspectiveMatrix[2][2] * input->z + perspectiveMatrix[2][3] * w;
}

void rotateX(Vertex *input, Vertex *output, float angle) {
  float angleRad = degreesToRad(angle);

  output->x = input->x;
  output->y = input->y * cos(angleRad) - input->z * sin(angleRad);
  output->z = input->y * sin(angleRad) + input->z * cos(angleRad);
}

void rotateY(Vertex *input, Vertex *output, float angle) {
  float angleRad = degreesToRad(angle);

  output->x = input->x * cos(angleRad) + input->z * sin(angleRad);
  output->y = input->y;
  output->z = -input->x * sin(angleRad) + input->z * cos(angleRad);
}