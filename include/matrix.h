#ifndef MATRIX_H
#define MATRIX_H

#include "block.h"

float degreesToRad(float degrees);

/*
 * Caluculate perspective projection transform
 * input: input vector
 * output: vector where the result is to be stored
 * width: window width
 * height: window heigth
 */
void perspectiveTransform(Vector3d *input, Vector3d *output, int width, int height);

/*
 * Rotate vector in three dimensions
 * orientation: the angles to rotate to
 */
void rotateVector(Vector3d *input, Vector3d *output, Orientation *orientation);

/*
 *Calculate cross product
 * a: first opearand
 * b: second operand
 * output: resulting vector
 */
void vectorCrossProduct(Vector3d *a, Vector3d *b, Vector3d *output);

/*
 * returns: dot product
 * a: first opearand
 * b: second operand
 */
float vectorDotProduct(Vector3d *a, Vector3d *b);

/*
 * Subract vector a from vector b
 * a: first opearand
 * b: second operand
 */
void vectorSubtract(Vector3d *a, Vector3d *b, Vector3d *output);

/*
 * Duplicate vector a into vector output
 */
void duplicateVector(Vector3d *a, Vector3d *output);

#endif