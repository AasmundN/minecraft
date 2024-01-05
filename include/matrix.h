#ifndef MATRIX_H
#define MATRIX_H

#include "block.h"

/*
 * Caluculate perspective projection transform
 * input: input vector
 * output: vector where the result is to be stored
 * width: window width
 * height: window heigth
 */
void perspectiveTransform(Vertex *input, Vertex *output, int width, int height);

/*
 * Rotate vector in three dimensions
 * orientation: the angles to rotate to
 */
void rotateVector(Vertex *input, Vertex *output, Orientation *orientation);

#endif