#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "circles.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

int main(){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* mainWindow = SDL_CreateWindow("Raytracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Surface* mainSurface = SDL_GetWindowSurface(mainWindow);

    Circle c = (Circle) {WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 50};

    short engine_is_running = 1;
    while(engine_is_running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                engine_is_running = 0;
            }
        }

        DrawCircle(mainSurface, c);
        SDL_UpdateWindowSurface(mainWindow);
        SDL_Delay(1000);
    }

    return 0;
}