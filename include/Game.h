#ifndef GAME_H
#define GAME_H

#include "Dungeon.h"
#include "Player.h"
#include "Shader.h" // Custom shader helper
#include <vector>

// Include OpenGL and GLM headers as needed
#include <glad/glad.h>
#include <glm/glm.hpp>

class Game {
public:
    Game();
    ~Game();

    bool init();
    void run();
    void handleEvents();
    void update();
    void render();
    void cleanUp();

private:
    bool running;
    Dungeon* dungeon;
    std::vector<Player*> players;

    // New members for normal mapping
    Shader* normalMappingShader;  // Shader for normal mapping
    unsigned int diffuseTexture;  // Diffuse map texture
    unsigned int normalTexture;   // Normal map texture
};

#endif // GAME_H
