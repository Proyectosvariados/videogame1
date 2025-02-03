#include "Dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Dungeon::Dungeon() {
    cells.resize(HEIGHT, std::vector<int>(WIDTH, 0));
    srand(static_cast<unsigned>(time(nullptr)));
}

Dungeon::~Dungeon() {}

void Dungeon::generateMap() {
    // Ejemplo sencillo: asigna un ID de tile aleatorio (0-2) a cada celda
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cells[i][j] = rand() % 3;
        }
    }
}

void Dungeon::drawDungeon() {
    // Representación en consola (para pruebas o debug)
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            std::cout << cells[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
