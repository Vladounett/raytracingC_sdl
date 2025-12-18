#include "circles.h"
#include <math.h>

//(x−cx)^2+(y−cy)^2 <= r^2 in the circle

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

    /**for(double x = circle.x - circle.radius; x <= circle.x + circle.radius; x++){
        for(double y = circle.y - circle.radius; y <= circle.y + circle.radius; y++){

            if(pow(x - circle.x, 2) + pow(y - circle.y, 2) <= pow(circle.radius, 2)){ //(x−cx)^2+(y−cy)^2 <= r^2
                SDL_FillRect(surface, &(SDL_Rect){x, y, 1, 1}, 0xFFFFFFFF);
            }
        }
    } naive way **/
}