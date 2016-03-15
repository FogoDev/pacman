#include "loadTexture.h"

SDL_Texture *loadTexture(const char *path)
{
    // A textura final
    SDL_Texture *newTexture = NULL;
    
    // Carega uma imagem especificada pelo path
    SDL_Surface *loadedSurface = IMG_Load(path);
    if(!loadedSurface){
        printf("Não foi possível carregar a imagem %s! SDL Error: %s\n", path, SDL_GetError());
    } else {
        // Cria a textura a partir dos pixels da superficie
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if(!newTexture){
            printf("Não foi possível criar a texture a partir da imagem %s! SDL Error: %s\n", path, SDL_GetError());
        }
        
        // Se livra do ponteiro pra loadedSurface
        SDL_FreeSurface(loadedSurface);
    }
    
    return newTexture;
}