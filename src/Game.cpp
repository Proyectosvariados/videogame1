#include "Game.h"
#include "Dungeon.h"
#include "Player.h"
#include "Shader.h"          // Custom shader helper class
#include "TextureLoader.h"   // loadTexture() function (using stb_image, for example)
#include <iostream>

// GLM for math operations
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Game::Game() 
    : running(false), dungeon(nullptr), normalMappingShader(nullptr),
      diffuseTexture(0), normalTexture(0) {}

Game::~Game() {
    // Resources will be freed in cleanUp()
}

bool Game::init() {
    // Initialize SDL/GLFW and OpenGL context, load assets, etc.
    // Example: Initialize SDL, create window, load GLAD, etc.

    // Create and generate the dungeon
    dungeon = new Dungeon();
    dungeon->generateMap();

    // Create players (example with a single player)
    Player* player = new Player("Guerrero");
    players.push_back(player);

    // Load the normal mapping shader from the assets/shaders directory
    normalMappingShader = new Shader("assets/shaders/normal_mapping.vert", "assets/shaders/normal_mapping.frag");

    // Load textures: diffuse texture and corresponding normal map
    diffuseTexture = loadTexture("assets/textures/asset_diffuse.png");
    normalTexture  = loadTexture("assets/textures/asset_normal.png");

    // Enable depth testing if needed
    glEnable(GL_DEPTH_TEST);

    running = true;
    return true;
}

void Game::run() {
    while (running) {
        handleEvents();
        update();
        render();
        // Insert FPS control or time step management here
    }
}

void Game::handleEvents() {
    // Handle keyboard, mouse, and other events
    // Example: if (event.key == SDLK_ESCAPE) running = false;
}

void Game::update() {
    // Update game logic: players, enemies, AI, skills, etc.
    // You may also update any time-based uniforms here.
}

void Game::render() {
    // Clear the screen (color and depth buffers)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up transformation matrices using GLM
    glm::mat4 modelMatrix = glm::mat4(1.0f);  // Identity matrix or specific transform for your scene
    glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),   // Camera position
                                       glm::vec3(0.0f, 0.0f, 0.0f),   // Look at point
                                       glm::vec3(0.0f, 1.0f, 0.0f));  // Up vector
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), 
                                                  800.0f / 600.0f, 
                                                  0.1f, 100.0f);

    // Activate the normal mapping shader
    normalMappingShader->use();

    // Set shader uniforms for transformation matrices
    normalMappingShader->setMat4("model", modelMatrix);
    normalMappingShader->setMat4("view", viewMatrix);
    normalMappingShader->setMat4("projection", projectionMatrix);

    // Set uniform variables for light and camera positions
    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
    glm::vec3 viewPos(0.0f, 0.0f, 3.0f);
    normalMappingShader->setVec3("lightPos", lightPos);
    normalMappingShader->setVec3("viewPos", viewPos);

    // Bind the textures to their corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseTexture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, normalTexture);

    // Set texture unit uniforms in the shader
    normalMappingShader->setInt("diffuseMap", 0);
    normalMappingShader->setInt("normalMap", 1);

    // Render your scene elements that use normal mapping.
    // For instance, render the dungeon and player meshes (which should include tangent data).
    dungeon->drawDungeon();
    for (auto player : players) {
        player->render();
    }

    // Swap buffers if using double-buffering (SDL_GL_SwapWindow(window) or equivalent)
}

void Game::cleanUp() {
    // Free memory, save game states, etc.
    delete dungeon;
    for (auto p : players) {
        delete p;
    }
    delete normalMappingShader;

    // Delete textures (if not managed elsewhere)
    glDeleteTextures(1, &diffuseTexture);
    glDeleteTextures(1, &normalTexture);

    // Additional cleanup for SDL/GLFW, etc.
}
