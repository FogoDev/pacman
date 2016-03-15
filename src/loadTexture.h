#ifndef _loadTexture_h
#define _loadTexture_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "constantsNdefines.h"
#include "globals.h"

// Carrega uma imagem individualmente como uma textura
SDL_Texture *loadTexture(const char *path);

#endif