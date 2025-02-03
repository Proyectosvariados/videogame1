#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <string>
#include <glad/glad.h>

// Loads a texture from file and returns its OpenGL texture ID.
// 'path' should be the path to the texture file.
unsigned int loadTexture(const char* path);

#endif // TEXTURE_LOADER_H
