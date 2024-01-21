#include "sort.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float sumZ(Face *quad)
{
  float sum = 0;
  for (int i = 0; i < 4; i++)
    sum += quad->vertices[i].z;

  return sum;
}

bool compareQuads(Face *a, Face *b)
{
  return sumZ(a) <= sumZ(b);
}

void merge(Face *array, int start, int split, int end)
{
  int sizeOne = split - start + 1;
  int sizeTwo = end - split;

  Face *subOne = malloc(sizeOne * sizeof(Face));
  Face *subTwo = malloc(sizeTwo * sizeof(Face));

  memcpy(subOne, &array[start], sizeOne * sizeof(Face));
  memcpy(subTwo, &array[split + 1], sizeTwo * sizeof(Face));

  int indexOne = 0;
  int indexTwo = 0;
  int mergedIndex = start;

  while (indexOne < sizeOne && indexTwo < sizeTwo)
  {
    if (compareQuads(&subOne[indexOne], &subTwo[indexTwo]))
    {
      array[mergedIndex] = subOne[indexOne];
      indexOne++;
    }
    else
    {
      array[mergedIndex] = subTwo[indexTwo];
      indexTwo++;
    }
    mergedIndex++;
  }

  while (indexOne < sizeOne)
  {
    array[mergedIndex] = subOne[indexOne];
    indexOne++;
    mergedIndex++;
  }

  while (indexTwo < sizeTwo)
  {
    array[mergedIndex] = subTwo[indexTwo];
    indexTwo++;
    mergedIndex++;
  }

  free(subOne);
  free(subTwo);
}

void mergeSort(Face *array, int start, int end)
{
  if (start >= end) return;

  int split = start + (end - start) / 2;

  mergeSort(array, start, split);
  mergeSort(array, split + 1, end);

  merge(array, start, split, end);
}