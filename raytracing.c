#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "geometry.h"
#include "const.h"

int main(int argc, char* argv[]){

    const SDL_Rect reset_rect = (SDL_Rect) {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* mainWindow = SDL_CreateWindow("Raytracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Surface* mainSurface = SDL_GetWindowSurface(mainWindow);

    Circle ray_circle = (Circle) {WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 40, atoi(argv[1]), NULL};
    Circle rayblocking_circle = (Circle) {WINDOW_WIDTH/2 + 300, WINDOW_HEIGHT/2, 100, 0, NULL};
    Circle rayblocking_circle2 = (Circle) {WINDOW_WIDTH/2 - 300, WINDOW_HEIGHT/2 + 200, 50, 0, NULL};

    Circle_node firstCollider = (Circle_node){rayblocking_circle, NULL};
    Circle_node secondCollider = (Circle_node){rayblocking_circle2, &firstCollider};

    short engine_is_running = 1;
    while(engine_is_running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                engine_is_running = 0;
            }else if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_UP: ray_circle.y -= MOVE_SPEED; break;
                    case SDLK_DOWN: ray_circle.y += MOVE_SPEED; break;
                    case SDLK_LEFT: ray_circle.x -= MOVE_SPEED; break;
                    case SDLK_RIGHT: ray_circle.x += MOVE_SPEED; break;
                }
            }
        }

        GenerateCircleRays(&ray_circle);

        SDL_FillRect(mainSurface, &reset_rect, 0x00000000); //draw background black before drawing circles
        DrawCircle(mainSurface, ray_circle);
        DrawCircles(mainSurface, &secondCollider);
        DrawRays(mainSurface, ray_circle.rays, ray_circle.rayNumber, WINDOW_WIDTH, WINDOW_HEIGHT, &secondCollider);

        SDL_UpdateWindowSurface(mainWindow);
        SDL_Delay(20);
    }

    return 0;
}