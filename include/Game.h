#ifndef GAME_H
#define GAME_H

#include "Dungeon.h"
#include "Player.h"
#include <vector>

class Game {
public:
    Game();
    ~Game();

    bool init();
    void run();
    void cleanUp();

private:
    void handleEvents();
    void update();
    void render();

    bool running;
    Dungeon* dungeon;
    std::vector<Player*> players;  // Soporta de 1 a 4 jugadores
    // Otros atributos: estado del menú, sistema de guardado, etc.
};

#endif // GAME_H
