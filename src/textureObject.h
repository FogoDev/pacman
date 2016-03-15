#ifndef _textureObject_h
#define _textureObject_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "constantsNdefines.h"


typedef struct _Texture_object {
    
    // Carrega imagem de um determinado path
    bool (*loadFromFile)(void *self, const char *path, SDL_Renderer *gRenderer);
    
    // Cria uma imagem de uma string de fonte
    bool (*loadFromRenderedText)(void *self, const char *textureText, SDL_Color textColor, SDL_Renderer *gRenderer, TTF_Font *gFont);
    
    // Desaloca a textura   
    void (*textureFree)(void *self);
    
    // Renderiza a textura em dado ponto
    void (*render)(void *self, int x, int y, SDL_Renderer *gRenderer, SDL_Rect *clip /* NULL */, double angle /* 0.0 */, SDL_Point *center /* NULL */, SDL_RendererFlip flip /* SDL_FLIP_NONE */);
    
    // Seta a modularização de cores
    void (*setColor)(void *self, uint8_t red, uint8_t green, uint8_t blue);
    
    // Seta o blend
    void (*setBlendMode)(void *self, SDL_BlendMode blending);
    
    // Seta a modularização do alpha
    void (*setAlpha)(void *self, uint8_t alpha);
       
    // A textura a ser renderizada pelo hardware
    SDL_Texture *mTexture;
    
    // As dimensões da imagem
    int mWidth;
    int mHeight;    
    
} Texture_object;

bool Texture_object_loadFromFile(void *self, const char *path, SDL_Renderer *gRenderer);
bool Texture_object_loadFromRenderedText(void *self, const char *textureText, SDL_Color textColor, SDL_Renderer *gRenderer, TTF_Font *gFont);
void Texture_object_textureFree(void *self);
void Texture_object_render(void *self, int x, int y, SDL_Renderer *gRenderer, SDL_Rect *clip /* NULL */, double angle /* 0.0 */, SDL_Point *center /* NULL */, SDL_RendererFlip flip /* SDL_FLIP_NONE */);
void Texture_object_setColor(void *self, uint8_t red, uint8_t green, uint8_t blue);
void Texture_object_setBlendMode(void *self, SDL_BlendMode blending);
void Texture_object_setAlpha(void *self, uint8_t alpha);

void Texture_object_new(Texture_object *texture);

#endif