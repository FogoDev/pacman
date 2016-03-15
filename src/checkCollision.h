#ifndef _checkCollision_h
#define _checkCollision_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "constantsNdefines.h"

// Detector de colisões quadrado / quadrado
bool checkSSCollision(SDL_Rect a[], SDL_Rect b[]);

// Detector de colisões circulo / quadrado
bool checkCSCollision(Circle a, SDL_Rect b);

// Detector de colisões circulo / circulo
bool checkCCCollision(Circle a, Circle b);

// Verifica se o pacman comeu uma pilula
bool eatPill(Circle pacman, SDL_Rect pillTile);

// Calcula a distância ao quadrado entre 2 pontos
double distanceSquared(int x1, int y1, int x2, int y2);

#endif