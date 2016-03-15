#ifndef _closeProgram_h
#define _closeProgram_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "constantsNdefines.h"
#include "globals.h"
#include "textureObject.h"

// Libera a midia e encerra o SDL
void closeProgram(Tile_object *tiles[]);

#endif