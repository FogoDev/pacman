#ifndef _loadMedia_h
#define _loadMedia_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "constantsNdefines.h"
#include "loadTexture.h"
#include "globals.h"
#include "textureObject.h"
#include "tileObject.h"

// Carrega midia
bool loadMedia(Tile_object *tiles[], SDL_Rect *gTileClips);

#endif