#ifndef _dotObject_h
#define _dotObject_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <time.h>
#include <stdlib.h>
#include "constantsNdefines.h"
#include "textureObject.h"
#include "checkCollision.h"
#include "tileObject.h"
#include "touchesWall.h"


struct _Dot_object {
    
    // As dimensões do ponto
    const int DOT_WIDTH;
    const int DOT_HEIGHT;
    
    // A velocidade máxima do ponto
    int DOT_VEL;
    
    // Pega os eventos de pressionar as teclas e ajusta a velocidade do ponto
    void (*handleEvent)(void *self, SDL_Event *e);
    
    // Move o ponto e checa colisões
    void (*move)(struct _Dot_object *dot, Tile_object *tiles[]);
    
    // Renderiza o ponto na tela
    void (*render)(void *self, Texture_object *texture, SDL_Renderer *gRenderer, SDL_Rect *gSpriteClip, double angle);
    
    // Posições X e Y do ponto
    // int mPosX, mPosY;
    
    // A velocidade do ponto
    int mVelX, mVelY;
    
    // A direção que o ponto está andando
    int mDirection;
    
    
    // Atributos exclusivos de fantasma
    bool mGhost;
    bool mXInversor;
    bool mYInversor;
    bool mDead;
    
    // Collision box do ponto
    SDL_Rect mBox;
    
    
}; 

typedef struct _Dot_object Dot_object;

void Dot_object_handleEvent(void *self, SDL_Event *e);
void Dot_object_move(Dot_object *dot, Tile_object *tiles[]);
void Dot_object_render(void *self, Texture_object *texture, SDL_Renderer *gRenderer, SDL_Rect *gSpriteClip, double angle);
void Dot_object_shiftColliders(void *self);
void Dot_object_moveGhost(Dot_object *ghost, Tile_object *tiles[]);

void Dot_object_new(Dot_object *dot, int x, int y, bool ghost);

#endif