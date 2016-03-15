#include "loadMedia.h"

bool loadMedia(Tile_object *tiles[], SDL_Rect *gTileClips)
{
    // Inicializando a flag
    bool success = true;
    
    
    
    
    // // Cores de renderização do texto
    // SDL_Color textColor = {0, 0, 0, 0xFF};
    // SDL_Color highlightColor = {0xFF, 0, 0, 0xFF};
    
    // // Abre a fonte
    // gFont = TTF_OpenFont("../res/fonts/lazy.ttf", 28);
    // if(gFont == NULL){
    //     printf("Falha ao carregar lazy font! SDL_ttf Error: %s\n", TTF_GetError());
    //     success = false;
    // } 
    // else {
    //     // Renderiza o texto
    //     if(!gPromptTextTexture.loadFromRenderedText(&gPromptTextTexture, "Insira os dados:", textColor, gRenderer, gFont)){
    //         printf("Falha ao renderizar a textura do texto!\n");
    //         success = false;
    //     }
    // }
    
    
    // // Abre o arquivo pra leitura binária
    // SDL_RWops *file = SDL_RWFromFile("../res/score/score.bin", "r+b");
    // if(file == NULL){
    //     printf("Aviso: Falha ao abrir arquivo de pontuação! SDL Error %s\n", SDL_GetError());
        
    //     // Cria o arquivo pra escrita
    //     file = SDL_RWFromFile("../res/score/score.bin", "w+b");
    //     if(file != NULL){
    //         printf("Novo arquivo de pontuação criado!\n");
            
    //         // Inicializa os dados
    //         for(int i = 0; i < TOTAL_DATA; i++){
    //             gData[i] = 0;
    //             SDL_RWwrite(file, &gData[i], sizeof(Sint32), 1);
    //         }
            
    //         // Fecha o manipulador de arquivos
    //         SDL_RWclose(file);
    //     } else {
    //         printf("Erro: Falha ao criar arquivo de pontuação! SDL Error %s\n", SDL_GetError());
    //         success = false;
    //     }
    // } else {
    //     // Lê os dados
    //     printf("Lendo arquivo de pontuação...!\n");
    //     for(int i = 0; i < TOTAL_DATA; i++){
    //         SDL_RWread(file, &gData[i], sizeof(Sint32), 1);
    //     }
        
    //     // Fecha o manipulador de arquivos
    //         SDL_RWclose(file);
    // }
    
    // // Inicializa as texturas dos dados
    // char buffer[13];
    // sprintf(buffer, "%d", gData[0]);
    // gDataTexture[0].loadFromRenderedText(&gDataTexture[0], buffer, highlightColor, gRenderer, gFont);
    // for(int i = 1; i < TOTAL_DATA; i++){
    //     memset(buffer, '\0', sizeof(char) * 13);
    //     sprintf(buffer, "%d", gData[i]);
    //     gDataTexture[i].loadFromRenderedText(&gDataTexture[i], buffer, textColor, gRenderer, gFont);
    // }
    
    // Carrega os sprites de botões
    // if(!gButtonSpriteSheetTexture.loadFromFile(&gButtonSpriteSheetTexture, "../res/images/button.png", gRenderer)){
    //     printf("Falha ao carregar a textura do sprite do botão!\n");
    //     success = false;
    // } else {
    //     // Seta os sprites
    //     for(int i = 0; i < BUTTON_SPRITE_TOTAL; i++){
    //         gSpriteClips[ i ].x = 0;
	// 		gSpriteClips[ i ].y = i * 200;
	// 		gSpriteClips[ i ].w = BUTTON_WIDTH;
	// 		gSpriteClips[ i ].h = BUTTON_HEIGHT;
    //     }
        
    //     //Set buttons in corners
	// 	gButtons[0].setPosition(&gButtons[0], 0, 0 );
	// 	gButtons[1].setPosition(&gButtons[1], SCREEN_WIDTH - BUTTON_WIDTH, 0 );
	// 	gButtons[2].setPosition(&gButtons[2], 0, SCREEN_HEIGHT - BUTTON_HEIGHT );
	// 	gButtons[3].setPosition(&gButtons[3], SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT );
    // }
    
    // Carrega as texturas press, up, down, left e right
    // if(!gPressTexture.loadFromFile(&gPressTexture, "../res/images/press.bmp", gRenderer)){
    //     printf("Falha ao carregar a textura de press!\n");
    //     success = false;
    // }
    
    // if(!gUpTexture.loadFromFile(&gUpTexture, "../res/images/up.bmp", gRenderer)){
    //     printf("Falha ao carregar a textura de up!\n");
    //     success = false;
    // }
    
    // if(!gDownTexture.loadFromFile(&gDownTexture, "../res/images/down.bmp", gRenderer)){
    //     printf("Falha ao carregar a textura de down!\n");
    //     success = false;
    // }
    
    // if(!gLeftTexture.loadFromFile(&gLeftTexture, "../res/images/left.bmp", gRenderer)){
    //     printf("Falha ao carregar a textura de left!\n");
    //     success = false;
    // }
    
    // if(!gRightTexture.loadFromFile(&gRightTexture, "../res/images/right.bmp", gRenderer)){
    //     printf("Falha ao carregar a textura de right!\n");
    //     success = false;
    // }
    
    //Carrega a textura de dot
    if(!gDotTexture.loadFromFile(&gDotTexture, "../res/images/dot.bmp", gRenderer)){
        printf("Falha ao carregar a textura do dot!\n");
        success = false;
    }
    
    // Carrega a textura dos tiles
    if(!gTileTexture.loadFromFile(&gTileTexture, "../res/sprites/map_sprites.png", gRenderer)){
        printf("Falha ao carregar a textura dos tiles!\n");
        success = false;
    }
    
    // Carrega o mapa de tiles
    if(!setTiles(tiles, gTileClips)){
        printf("Falha ao carregar o mapa de tiles!\n");
        success = false;
    }
    
    // // Carregaa música
    // gMusic = Mix_LoadMUS("../res/sound/music/beat.wav");
    // if(gMusic == NULL){
    //     printf("Falha ao carregar a música de fundo! SDL_mixer Error: %s\n", Mix_GetError());
    //     success = false;
    // }
    
    // // Carrega efeitos sonoros
    // gScratch = Mix_LoadWAV("../res/sound/effects/scratch.wav");
    // if(gScratch == NULL){
    //     printf("Falha ao carregar o efeito sonoro scratch! SDL_mixer Error: %s\n", Mix_GetError());
    //     success = false;
    // }

    // gHigh = Mix_LoadWAV("../res/sound/effects/high.wav");
    // if(gHigh == NULL){
    //     printf("Falha ao carregar o efeito sonoro high! SDL_mixer Error: %s\n", Mix_GetError());
    //     success = false;
    // }
    
    // gMedium = Mix_LoadWAV("../res/sound/effects/medium.wav");
    // if(gMedium == NULL){
    //     printf("Falha ao carregar o efeito sonoro medium! SDL_mixer Error: %s\n", Mix_GetError());
    //     success = false;
    // }
    
    // gLow = Mix_LoadWAV("../res/sound/effects/low.wav");
    // if(gLow == NULL){
    //     printf("Falha ao carregar o efeito sonoro low! SDL_mixer Error: %s\n", Mix_GetError());
    //     success = false;
    // }
    
    
    return success;
}