#include "geometry.h"
#include <math.h>

//(x−cx)^2+(y−cy)^2 <= r^2 in the circle

void GenerateCircleRays(Circle* circle){
    circle->rays = calloc(circle->rayNumber, sizeof(Ray));
    double angleByRayNumber = (double) 360 / (double) circle->rayNumber;

    for(int i = 0; i < circle->rayNumber; i++){
        double radiansAngle = (i * angleByRayNumber) * M_PI / (double) 180;
        circle->rays[i] = (Ray) {circle->x, circle->y, radiansAngle, cos(radiansAngle), -sin(radiansAngle)};
        //printf("angle in deg :: %f\n", i*angleByRayNumber);
        //printf("angle in radian :: %f\n", (i * angleByRayNumber) * M_PI / 180);
    }
}

void DrawRays(SDL_Surface* surface, Ray rays[], int rayNumber, int WINDOW_WIDTH, int WINDOW_HEIGHT, Circle_node* c_node){
    
    Circle_node* original_c_node = c_node;

    for(int i = 0; i < rayNumber; i++){
        short xInScreen = 1;
        short yInScreen = 1;
        short noHit = 1;
        int range = 0;
        //printf("i (dirx, diry) := %d (%f, %f)\n", i, rays[i].direction_x, rays[i].direction_y);
        while(xInScreen && yInScreen && noHit){
            c_node = original_c_node;

            int currentPixelPosX = rays[i].origin_x + range * rays[i].direction_x;
            int currentPixelPosY = rays[i].origin_y + range * rays[i].direction_y;

            while(c_node){ //going through colliders, to detect hits
                if(pow(currentPixelPosX - c_node->circle.x, 2) + pow(currentPixelPosY - c_node->circle.y, 2) <= pow(c_node->circle.radius, 2)){
                    noHit = 0;
                    break;
                }
                c_node = c_node->next;
            }

            SDL_FillRect(surface, &(SDL_Rect){currentPixelPosX, currentPixelPosY, 1, 1}, 0xFFFFFFFF);
            range++;

            if(currentPixelPosX < 0 || currentPixelPosX > WINDOW_WIDTH){
                xInScreen = 0;
            }
            if(currentPixelPosY < 0 || currentPixelPosY > WINDOW_HEIGHT){
                yInScreen = 0;
            }
        }
    }
}

void DrawCircle(SDL_Surface* surface, Circle circle){

    //mid-point circle algorithm

    int x = circle.radius;
    int y = 0;
    int p = 1 - circle.radius;
    
    while(x >= y){
        
        SDL_FillRect(surface, &(SDL_Rect){circle.x - x, circle.y + y, 2*x + 1, 1}, 0xFFFFFFFF);
        SDL_FillRect(surface, &(SDL_Rect){circle.x - x, circle.y - y, 2*x + 1, 1}, 0xFFFFFFFF);
        SDL_FillRect(surface, &(SDL_Rect){circle.x - y, circle.y + x, 2*y + 1, 1}, 0xFFFFFFFF);
        SDL_FillRect(surface, &(SDL_Rect){circle.x - y, circle.y - x, 2*y + 1, 1}, 0xFFFFFFFF);

        y++;

        if (p <= 0)
            p += 2*y + 1;
        else {
            x--;
            p += 2*y - 2*x + 1;
        }
    }
}

void DrawCircles(SDL_Surface* surface, Circle_node* c_node){
    while(c_node){
        Circle circle = c_node->circle;
        int x = circle.radius;
        int y = 0;
        int p = 1 - circle.radius;
            
        while(x >= y){
                
            SDL_FillRect(surface, &(SDL_Rect){circle.x - x, circle.y + y, 2*x + 1, 1}, 0xFFFFFFFF);
            SDL_FillRect(surface, &(SDL_Rect){circle.x - x, circle.y - y, 2*x + 1, 1}, 0xFFFFFFFF);
            SDL_FillRect(surface, &(SDL_Rect){circle.x - y, circle.y + x, 2*y + 1, 1}, 0xFFFFFFFF);
            SDL_FillRect(surface, &(SDL_Rect){circle.x - y, circle.y - x, 2*y + 1, 1}, 0xFFFFFFFF);

            y++;

            if (p <= 0)
                p += 2*y + 1;
            else {
                x--;
                p += 2*y - 2*x + 1;
            }
        }

        c_node = c_node->next;
    }
}