#ifndef CIRCLES_H
#define CIRCLES_H

#include <SDL2/SDL.h>
#include <stdlib.h>

typedef struct{
    double x, y;
    double radius;
} Circle;

void DrawCircle(SDL_Surface* surface, Circle circle);

#endif