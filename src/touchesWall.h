#ifndef _touchesWall_h
#define _touchesWall_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "constantsNdefines.h"
#include "checkCollision.h"
// #include "globals.h"
#include "tileObject.h"

// Checa a colisão contra os tijolos do mapa
bool touchesWall(Circle circle, Tile_object *tiles[], bool ghost);

#endif