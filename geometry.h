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
    double eyeDirection;
    double eyeMaxAngle;
    Ray* rays;
} Circle;

typedef struct{
    double x, y;
    double radius;
} CircleCollider;

typedef struct Circle_node{
    CircleCollider circle;
    struct Circle_node* next;
} Collider_node;

void DrawCircle(SDL_Surface* surface, Circle circle);
void DrawCircles(SDL_Surface* surface, Collider_node* c_node);
void DrawRays(SDL_Surface* surface, Ray rays[], int rayNumber, int WINDOW_WIDTH, int WINDOW_HEIGHT, Collider_node* c_node);
void GenerateCircleRays(Circle* circle);
void MoveWithDirection(Circle* circle, int movingDir);

#endif