#include "game.hpp"

Game::Game(){};
Game::~Game(){};

void Game::init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen){
    int flag = 0;
    if (fullscreen) flag = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "Subsystem Initialised...." << endl;

        window = SDL_CreateWindow(title,x_pos,y_pos,width,height,flag);
        if(window){
            win_width = width;
            win_height = height;
            cout << "Window Initialised...." << endl;
        }

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            cout << "Renderer Initialised...." << endl;
        }

        is_running = true;
    }
    else is_running = false;
};

void Game :: handle_event(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            is_running = false;
            break;
        
        default:
        break;
    }
};

void Game :: update(){
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
};

void Game :: draw_rectangle(int x_pos,int height){
    rect.x = rect.w*x_pos;
    rect.h = height;
    rect.y = win_height - rect.h;
    SDL_RenderDrawRect(renderer,&rect);
};

void Game :: render(){
    SDL_RenderClear(renderer);
    // other render stuff
    SDL_SetRenderDrawColor(renderer,255,255,255,150);
    for (int i = 0;i < 10;i++) draw_rectangle(i,rects[i]);
    SDL_RenderPresent(renderer);
};

void Game :: clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "EXIT SUCCESSFULLY" << endl;
};

bool Game :: running(){
    return is_running;
};