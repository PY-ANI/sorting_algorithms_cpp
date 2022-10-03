#include "game.hpp"

Game * game = nullptr;

int main(int argc, const char * argv[]){

    game = new Game();

    game -> init("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,false);
    
    while (game -> running()){
        game -> handle_event();
        game -> update();
        game -> render();
    }

    game -> clean();

    return 0;
}