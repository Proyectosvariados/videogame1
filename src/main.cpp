#include "Game.h"

int main() {
    Game game;
    if (game.init()) {
        game.run();
    }
    game.cleanUp();
    return 0;
}