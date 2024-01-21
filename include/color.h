#ifndef COLORS_H
#define COLORS_H

#include "app.h"

/*
 * Color hex value map
 */
extern char color[][8];

/*
 * Color names
 */
typedef enum
{
  RED,
  BLACK
} Color;

/*
 * Set renderer draw color using hex string
 */
void setRenderColor(struct App *app, const char *color);

#endif