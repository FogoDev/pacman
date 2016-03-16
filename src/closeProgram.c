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
    
    
    // Libera as texturas
    gPacmanTexture.textureFree(&gPacmanTexture);
    gTileTexture.textureFree(&gTileTexture);
    gScoreTextTexture.textureFree(&gScoreTextTexture);
    gLivesTextTexture.textureFree(&gLivesTextTexture);
    gPointsTextTexture.textureFree(&gPointsTextTexture);
    gDevTextTexture.textureFree(&gDevTextTexture);
    gPacmanLogoTexture.textureFree(&gPacmanLogoTexture);
    gPressEnterTextTexture.textureFree(&gPressEnterTextTexture);
    
    // for(int i = 0; i < TOTAL_DATA; i++){
    //    gDataTexture[i].textureFree(&gDataTexture[i]);
    // }
    
    
    // Libera os efeitos sonoros
    Mix_FreeChunk(gDiesSoundEffect);
    Mix_FreeChunk(gEatingCherrySoundEffect);
    Mix_FreeChunk(gEatingGhostSoundEffect);
    Mix_FreeChunk(gExtraLiveSoundEffect);
    Mix_FreeChunk(gOpeningSoundEffect);
    Mix_FreeChunk(gWakaWakaSoundEffect);
    
    gDiesSoundEffect = NULL;
    gEatingCherrySoundEffect = NULL;
    gEatingGhostSoundEffect = NULL;
    gExtraLiveSoundEffect = NULL;
    gOpeningSoundEffect = NULL;
    gWakaWakaSoundEffect = NULL;
    
    // Libera a música
    Mix_FreeChunk(gSirenMusic);
    Mix_FreeChunk(gIntermissionMusic);
    gSirenMusic = NULL;
    gIntermissionMusic = NULL;
    
    // Libera a fonte global
    TTF_CloseFont(gFont);
    TTF_CloseFont(gDevFont);
    gFont = NULL;
    gDevFont = NULL;
    
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