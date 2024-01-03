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

void rotateX(Vertex *input, Vertex *output, float angle);

void rotateY(Vertex *input, Vertex *output, float angle);

#endif