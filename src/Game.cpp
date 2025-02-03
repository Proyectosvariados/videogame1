#include "Game.h"
#include <iostream>

Game::Game() : running(false), dungeon(nullptr) {}

Game::~Game() {
    // Liberar recursos
}

bool Game::init() {
    // Inicialización de SDL o motor gráfico, carga de assets, etc.
    dungeon = new Dungeon();
    dungeon->generateMap();

    // Crear jugadores (ejemplo con un solo jugador)
    Player* player = new Player("Guerrero");
    players.push_back(player);

    running = true;
    return true;
}

void Game::run() {
    while (running) {
        handleEvents();
        update();
        render();
        // Control de FPS / tiempo real
    }
}

void Game::handleEvents() {
    // Manejar entradas del teclado, mouse, etc.
}

void Game::update() {
    // Actualizar estado de jugadores, enemigos, IA, habilidades, etc.
}

void Game::render() {
    // Renderizar el mapa, entidades, UI, etc.
}

void Game::cleanUp() {
    // Liberar memoria, guardar estados, etc.
    delete dungeon;
    for (auto p : players) {
        delete p;
    }
}
