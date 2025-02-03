#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>

class Dungeon {
public:
    Dungeon();
    ~Dungeon();

    // Genera el mapa de la mazmorra de forma procedural
    void generateMap();
    // Dibuja la mazmorra (aquí se muestra un ejemplo por consola)
    void drawDungeon();

private:
    static const int WIDTH = 4;
    static const int HEIGHT = 4;
    // Cada celda puede almacenar un entero que representa el ID del tile
    std::vector<std::vector<int>> cells;
};

#endif // DUNGEON_H
