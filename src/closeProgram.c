#include "closeProgram.h"

void closeProgram(Tile_object *tiles[])
{
    
    // Desaloca os Tiles
	for(int i = 0; i < TOTAL_TILES; i++){
		 if(tiles[i] != NULL){
			free(tiles[i]);
			tiles[i] = NULL;
		 }
	}
    
    // // Abre os dados para escrita
    // SDL_RWops *file = SDL_RWFromFile("../res/score/score.bin", "w+b");
    // if(file != NULL){
    //     // Salva os dados
    //     for(int i = 0; i < TOTAL_DATA; i++){
    //         SDL_RWwrite(file, &gData[i], sizeof(Sint32), 1);
    //     }
        
    //     // Fecha o manipulador de arquivos
    //     SDL_RWclose(file);
    // } else {
    //     printf("Erro: Falha ao salvar o arquivo de pontuação! SDL Error %s\n", SDL_GetError());
    // }
    
    
    // Desaloca textura da memória
    //gButtonSpriteSheetTexture.textureFree(&gButtonSpriteSheetTexture);
    // gPressTexture.textureFree(&gPressTexture);
    // gUpTexture.textureFree(&gUpTexture);
    // gDownTexture.textureFree(&gDownTexture);
    // gLeftTexture.textureFree(&gLeftTexture);
    // gRightTexture.textureFree(&gRightTexture);
    gDotTexture.textureFree(&gDotTexture);
    gTileTexture.textureFree(&gTileTexture);
    // gPromptTextTexture.textureFree(&gPromptTextTexture);
    // for(int i = 0; i < TOTAL_DATA; i++){
    //    gDataTexture[i].textureFree(&gDataTexture[i]);
    // }
    
    
    // // Libera os efeitos sonoros
    // Mix_FreeChunk(gScratch);
    // Mix_FreeChunk(gHigh);
    // Mix_FreeChunk(gMedium);
    // Mix_FreeChunk(gLow);
    // gScratch = NULL;
    // gHigh = NULL;
    // gMedium = NULL;
    // gLow = NULL;
    
    // Libera a música
    // Mix_FreeMusic(gMusic);
    // gMusic = NULL;
    
    // Libera a fonte global
    TTF_CloseFont(gFont);
    gFont = NULL;
    
    // Destroi a janela
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    
    // Encerra todos os subsistemas do SDL
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}