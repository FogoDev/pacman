#include "loadMedia.h"

bool loadMedia(Tile_object *tiles[], SDL_Rect *gTileClips)
{
    // Inicializando a flag
    bool success = true;
    
    // Cores de renderização do texto
    SDL_Color textColor = {0xFF, 0xFF, 0xFF, 0xFF};
    
    // Abre a fonte
    gFont = TTF_OpenFont("../res/fonts/emulogic.ttf", 28);
    if(gFont == NULL){
        printf("Falha ao carregar fonte de jogo! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    } 
    else {
        // Renderiza o texto
        if(!gScoreTextTexture.loadFromRenderedText(&gScoreTextTexture, "Score:", textColor, gRenderer, gFont)){
            printf("Falha ao renderizar a textura do texto de score!\n");
            success = false;
        }
        
        if(!gLivesTextTexture.loadFromRenderedText(&gLivesTextTexture, "Lives:", textColor, gRenderer, gFont)){
            printf("Falha ao renderizar a textura do texto da pontuação!\n");
            success = false;
        }
    }
    
    gDevFont = TTF_OpenFont("../res/fonts/emulogic.ttf", 22);
    if(gDevFont == NULL){
        printf("Falha ao carregar fonte de jogo! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    } else {
        
        if(!gDevTextTexture.loadFromRenderedText(&gDevTextTexture, "github.com/FogoDev/pacman", textColor, gRenderer, gDevFont)){
            printf("Falha ao renderizar a textura do texto de desenvolvedor!\n");
            success = false;
        }
        
        if(!gPressEnterTextTexture.loadFromRenderedText(&gPressEnterTextTexture, "Pressione ENTER para jogar", textColor, gRenderer, gDevFont)){
            printf("Falha ao renderizar a textura do texto da pontuação!\n");
            success = false;
        }
    }
    
    if(!gPacmanLogoTexture.loadFromFile(&gPacmanLogoTexture, "../res/sprites/pacman_logo.png", gRenderer)){
        printf("Falha ao carregar a textura de Logo do Pacman!\n");
        success = false;
    }
    
    
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
    
    
    //Carrega a textura de dot
    if(!gPacmanTexture.loadFromFile(&gPacmanTexture, "../res/sprites/map_sprites.png", gRenderer)){
        printf("Falha ao carregar a textura do pacman!\n");
        success = false;
    } else {
        
        // Seta os sprite clips
        gPacmanSpriteClips[0].x = 0;
        gPacmanSpriteClips[0].y = 192;
        gPacmanSpriteClips[0].w = TILE_WIDTH;
        gPacmanSpriteClips[0].h = TILE_HEIGHT;
        
        gPacmanSpriteClips[1].x = 32;
        gPacmanSpriteClips[1].y = 192;
        gPacmanSpriteClips[1].w = TILE_WIDTH;
        gPacmanSpriteClips[1].h = TILE_HEIGHT;
        
        gPacmanSpriteClips[2].x = 64;
        gPacmanSpriteClips[2].y = 192;
        gPacmanSpriteClips[2].w = TILE_WIDTH;
        gPacmanSpriteClips[2].h = TILE_HEIGHT;
        
        gPacmanSpriteClips[3].x = 96;
        gPacmanSpriteClips[3].y = 192;
        gPacmanSpriteClips[3].w = TILE_WIDTH;
        gPacmanSpriteClips[3].h = TILE_HEIGHT;
        
        
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
    
    // Carrega música siren
    gSirenMusic = Mix_LoadWAV("../res/sound/music/siren.ogg");
    if(gSirenMusic == NULL){
        printf("Falha ao carregar a música de siren! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    
    // Carrega música intermission
    gIntermissionMusic = Mix_LoadWAV("../res/sound/music/intermission.ogg");
    if(gIntermissionMusic == NULL){
        printf("Falha ao carregar a música de intermission! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    
    
    // Carrega efeitos sonoros do jogo
    gDiesSoundEffect = Mix_LoadWAV("../res/sound/effects/dies.ogg");
    if(gDiesSoundEffect == NULL){
        printf("Falha ao carregar o efeito sonoro dies! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    gEatingCherrySoundEffect = Mix_LoadWAV("../res/sound/effects/eating_cherry.ogg");
    if(gEatingCherrySoundEffect == NULL){
        printf("Falha ao carregar o efeito sonoro eating_cherry! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    
    gEatingGhostSoundEffect = Mix_LoadWAV("../res/sound/effects/eating_ghost.ogg");
    if(gEatingGhostSoundEffect == NULL){
        printf("Falha ao carregar o efeito sonoro eating_ghost! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    
    gExtraLiveSoundEffect = Mix_LoadWAV("../res/sound/effects/extra_live.ogg");
    if(gExtraLiveSoundEffect == NULL){
        printf("Falha ao carregar o efeito sonoro extra_live! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    
    gOpeningSoundEffect = Mix_LoadWAV("../res/sound/effects/opening.ogg");
    if(gOpeningSoundEffect == NULL){
        printf("Falha ao carregar o efeito sonoro opening! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    
    gWakaWakaSoundEffect = Mix_LoadWAV("../res/sound/effects/waka_waka.ogg");
    if(gWakaWakaSoundEffect == NULL){
        printf("Falha ao carregar o efeito sonoro waka_waka! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    
    return success;
}