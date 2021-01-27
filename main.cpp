#include <iostream>
#include "Game.h"

int main() {


    //game object
    Game game;

    //game loop
    while(game.getWindow()->isOpen()) {

        game.dt= game.dt_clock.restart().asSeconds();

        //calling the main run event
        game.runGame();

    }

    //game.getMazeStructure();
    return 0;
}
