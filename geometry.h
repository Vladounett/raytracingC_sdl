#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <SDL2/SDL.h>
#include <stdlib.h>

typedef struct{
    double origin_x, origin_y;
    double angle_rad;
    double direction_x, direction_y;
} Ray;

typedef struct{
    double x, y;
    double radius;
    int rayNumber;
    Ray* rays;
} Circle;

typedef struct Circle_node{
    Circle circle;
    struct Circle_node* next;
} Circle_node;

void DrawCircle(SDL_Surface* surface, Circle circle);
void DrawCircles(SDL_Surface* surface, Circle_node* c_node);
void DrawRays(SDL_Surface* surface, Ray rays[], int rayNumber, int WINDOW_WIDTH, int WINDOW_HEIGHT, Circle_node* c_node);
void GenerateCircleRays(Circle* circle);

#endif