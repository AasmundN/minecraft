#include "matrix.h"
#include "app.h"

#include <math.h>

#define PI 3.14159

float degreesToRad(float degrees) {
  return (PI * degrees) / 180;
}

void perspectiveTransform(Vector3d *input, Vector3d *output, int width, int height) {
  /*
   * Define constants
   */
  const float theta = 20;
  const float zFar = 1000;
  const float zNear = 0.1;
  const float aspectRatio = (float)height / (float)width;
  const float fieldOfView = 1 / tan(degreesToRad(theta / 2));
  const float q = zFar / (zFar - zNear);

  /*
   * Define perspective projection matrix
   */
  const float perspectiveMatrix[4][4] = {
      {aspectRatio * fieldOfView, 0, 0, 0},
      {0, fieldOfView, 0, 0},
      {0, 0, q, -zNear * q},
      {0, 0, 1, 0},
  };

  /*
   * Perform matrix multiplication
   */
  output->x = input->x * perspectiveMatrix[0][0];
  output->y = input->y * perspectiveMatrix[1][1];
  output->z = input->z * perspectiveMatrix[2][2] + perspectiveMatrix[2][3];
  const float w = input->z * perspectiveMatrix[3][2];

  if (w != 0) {
    output->x /= w;
    output->y /= w;
    output->z /= w;
  }
}

void rotateX(Vector3d *input, Vector3d *output, float angle) {
  float angleRad = degreesToRad(angle);

  output->x = input->x;
  output->y = input->y * cos(angleRad) - input->z * sin(angleRad);
  output->z = input->y * sin(angleRad) + input->z * cos(angleRad);
}

void rotateY(Vector3d *input, Vector3d *output, float angle) {
  float angleRad = degreesToRad(angle);

  output->x = input->x * cos(angleRad) + input->z * sin(angleRad);
  output->y = input->y;
  output->z = -input->x * sin(angleRad) + input->z * cos(angleRad);
}

void rotateZ(Vector3d *input, Vector3d *output, float angle) {
  float angleRad = degreesToRad(angle);

  output->x = input->x * cos(angleRad) - input->y * sin(angleRad);
  output->y = input->x * sin(angleRad) + input->y * cos(angleRad);
  output->z = input->z;
}

void rotateVector(Vector3d *input, Vector3d *output, Orientation *orientation) {
  Vector3d temp1, temp2;
  rotateX(input, &temp1, orientation->angleX);
  rotateY(&temp1, &temp2, orientation->angleY);
  rotateZ(&temp2, output, orientation->angleZ);
}

void vectorCrossProduct(Vector3d *a, Vector3d *b, Vector3d *output) {
  output->x = a->y * b->z - a->z * b->y;
  output->y = a->z * b->x - a->x * b->z;
  output->z = a->x * b->y - a->y * b->x;
}

float vectorDotProduct(Vector3d *a, Vector3d *b) {
  return a->x * b->x + a->y * b->y + a->z * b->z;
}

void vectorSubtract(Vector3d *a, Vector3d *b, Vector3d *output) {
  output->x = b->x - a->x;
  output->y = b->y - a->y;
  output->z = b->z - a->z;
}

void duplicateVector(Vector3d *a, Vector3d *output) {
  output->x = a->x;
  output->y = a->y;
  output->z = a->z;
}