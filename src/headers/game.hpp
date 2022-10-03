#ifndef game_hpp
#define game_hpp

#define SDL_MAIN_HANDLED
#include <iostream>
#include "SDL.h"

using namespace std;

class Game{
    public:
        Game();
        ~Game();

        void init(const char * title, int x_pos,int y_pos,int width,int height,bool fullscreen);

        void handle_event();
        void update();
        void render();
        void clean();

        void draw_rectangle(int x_pos,int height);        
        bool running();

    private:
        bool is_running;

        int win_width,win_height,rects[10] = {50,100,400,150,300,280,230,180,440,120};

        SDL_Window * window;
        SDL_Renderer * renderer;

        SDL_Rect rect = {100,100,50,50};
};

#endif /* game_hpp */