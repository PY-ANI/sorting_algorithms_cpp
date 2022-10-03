#include<SDL.h>
#include<iostream>

using namespace std;

int main(int argc, char * argv[]){
    
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) > 0){
        cout<<"SDL init failed with error :: " << SDL_GetError()<<endl;
    }

    SDL_Window * window;
    SDL_Renderer * renderer;

    window = SDL_CreateWindow("SDL_tut_2",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,500,500,SDL_WINDOW_SHOWN);

    if (window == NULL){
        cout<< "window init. failed with error :: "<< SDL_GetError()<<endl;
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer,255,10,10,155);
    
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(3000);

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}