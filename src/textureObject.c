#include "textureObject.h"


bool Texture_object_loadFromFile(void *self, const char *path, SDL_Renderer *gRenderer)
{
    Texture_object *texture = self;
    
    // Se livra da textura anterior
    texture->textureFree(texture);
    
    // A textura final
    SDL_Texture *newTexture = NULL;
    
    // Carrega a imagem do path especificado
    SDL_Surface *loadedSurface= IMG_Load(path);
    if(loadedSurface == NULL){
        printf("Não foi possível carregar a imagem %s! SDL_Image Error: %s\n", path, IMG_GetError());
    } else {
        // Color key da imagem
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        
        // Cria a textura a partir dos pixels da superficie
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if(newTexture == NULL){
            printf("Não foi possível carregar a textura a partir de %s! SDL Error: %s\n", path, SDL_GetError());
        } else {
            // Pega as dimensões da imagem
            texture->mWidth = loadedSurface->w;
            texture->mHeight = loadedSurface->h;
        }
        
        // Se livra da surface velha
        SDL_FreeSurface(loadedSurface);
    }
    
    // Retorna success
    texture->mTexture = newTexture;
    
    return texture->mTexture != NULL;   
}

bool Texture_object_loadFromRenderedText(void *self, const char *textureText, SDL_Color textColor, SDL_Renderer *gRenderer, TTF_Font *gFont)
{
    Texture_object *texture = self;
    
    // Se livra da textura anterior
    texture->textureFree(texture);
    
    // Renderiza a surface do texto
    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, textureText, textColor);
    if(textSurface == NULL){
        printf("Não foi possível renderizar a surface do texto! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        // Cria a textura dos pixels da surface
        texture->mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if(texture->mTexture == NULL){
            printf("Não foi possível criar a textura a partir do texto renderizado! SDL Error: %s\n", SDL_GetError());
        } else {
            // Pega as dimensões da imagem
            texture->mWidth = textSurface->w;
            texture->mHeight = textSurface->h;
        }
        
        // Se livra da surface velha
        SDL_FreeSurface(textSurface);
    }
    
    // Retorna o success
    return texture->mTexture != NULL;
}

void Texture_object_textureFree(void *self)
{
    Texture_object *texture = self;
    
    if(texture->mTexture != NULL){
        SDL_DestroyTexture(texture->mTexture);
        texture->mTexture = NULL;
        texture->mWidth = 0;
        texture->mHeight = 0;
    }
}


void Texture_object_render(void *self, int x, int y, SDL_Renderer *gRenderer, SDL_Rect *clip /* NULL */, double angle /* 0.0 */, SDL_Point *center /* NULL */, SDL_RendererFlip flip /* SDL_FLIP_NONE */)
{
    Texture_object *texture = self; 
    
    // Seta o espaço para renderizar e renderiza na tela
    SDL_Rect renderQuad= { x, y, texture->mWidth, texture->mHeight};
    if(clip != NULL){
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    // Renderiza na tela
    SDL_RenderCopyEx(gRenderer, texture->mTexture, clip, &renderQuad, angle, center, flip);
}

void Texture_object_setColor(void *self, uint8_t red, uint8_t green, uint8_t blue)
{
    Texture_object *texture = self;
    
    // Modula a textura
    SDL_SetTextureColorMod(texture->mTexture, red, green, blue);
}

void Texture_object_setBlendMode(void *self, SDL_BlendMode blending)
{
    Texture_object *texture = self;
    
    // Seta a função de blendmode
    SDL_SetTextureBlendMode(texture->mTexture, blending);
}

void Texture_object_setAlpha(void *self, uint8_t alpha)
{
    Texture_object *texture = self;
    
    // Modulariza o alpha da textura
    SDL_SetTextureAlphaMod(texture->mTexture, alpha);
}

void Texture_object_new(Texture_object *texture)
{   
    if(!texture->loadFromFile) texture->loadFromFile = Texture_object_loadFromFile;
    if(!texture->textureFree) texture->textureFree = Texture_object_textureFree;
    if(!texture->render) texture->render = Texture_object_render;
    if(!texture->setColor) texture->setColor = Texture_object_setColor;
    if(!texture->setBlendMode) texture->setBlendMode = Texture_object_setBlendMode;
    if(!texture->setAlpha) texture->setAlpha = Texture_object_setAlpha;
    if(!texture->loadFromRenderedText) texture->loadFromRenderedText = Texture_object_loadFromRenderedText;
    
    texture->mTexture = NULL;
    texture->mWidth = 0;
    texture->mHeight = 0;
}