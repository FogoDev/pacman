#ifndef _buttonObject_h
#define _buttonObject_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "constantsNdefines.h"
#include "textureObject.h"

typedef struct _Button_object {
    
    // Seta a posição do canto superior esquerdo da tela
    void (*setPosition)(void *self, int x, int y);
    
    // Manipula os eventos do mouse
    void (*handleEvent)(void *self, SDL_Event *e);
    
    // Renderiza o sprite do botão
    void (*render)(void *self, Texture_object *texture, SDL_Renderer *gRenderer, SDL_Rect *gSpriteClips);
    
    // Posição do canto superior esquerdo da tela
    SDL_Point mPosition;
    
    // Sprite global usado atualmente
    ButtonSprite mCurrentSprite;
    
} Button_object;

void Button_object_setPosition(void *self, int x, int y);
void Button_object_handleEvent(void *self, SDL_Event *e);
void Button_object_render(void *self, Texture_object *texture, SDL_Renderer *gRenderer, SDL_Rect *gSpriteClips);

void Button_object_new(Button_object *button);

#endif