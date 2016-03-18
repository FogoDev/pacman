#include "loadMedia.h"

bool loadMedia(Tile_object *tiles[], SDL_Rect *gTileClips)
{
    // Inicializando a flag
    bool success = true;
    
//////////////////////////// TEXTOS ////////////////////////////    
    
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
        
        if(!gNewLevelTextTexture.loadFromRenderedText(&gNewLevelTextTexture, "Nivel 1", textColor, gRenderer, gFont)){
            printf("Falha ao renderizar a textura do texto de nível 1!\n");
            success = false;
        }
        
        if(!gGameOverTextTexture.loadFromRenderedText(&gGameOverTextTexture, "Game Over", textColor, gRenderer, gFont)){
            printf("Falha ao renderizar a textura do texto de game over!\n");
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
    
/////////////////////////////////////////////////////////////////  
    
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
    
//////////////////////////// PACMAN ////////////////////////////

    // Carrega a textura do Pacman
    if(!gPacmanTexture.loadFromFile(&gPacmanTexture, "../res/sprites/map_sprites.png", gRenderer)){
        printf("Falha ao carregar a textura do pacman!\n");
        success = false;
    } else {
        
        // Seta os sprite clips do pacman
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
        
        gPacmanDiesSpriteClips[0].x = 0;
        gPacmanDiesSpriteClips[0].y = 384;
        gPacmanDiesSpriteClips[0].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[0].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[1].x = 32;
        gPacmanDiesSpriteClips[1].y = 384;
        gPacmanDiesSpriteClips[1].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[1].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[2].x = 64;
        gPacmanDiesSpriteClips[2].y = 384;
        gPacmanDiesSpriteClips[2].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[2].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[3].x = 96;
        gPacmanDiesSpriteClips[3].y = 384;
        gPacmanDiesSpriteClips[3].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[3].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[4].x = 128;
        gPacmanDiesSpriteClips[4].y = 384;
        gPacmanDiesSpriteClips[4].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[4].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[5].x = 160;
        gPacmanDiesSpriteClips[5].y = 384;
        gPacmanDiesSpriteClips[5].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[5].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[6].x = 192;
        gPacmanDiesSpriteClips[6].y = 384;
        gPacmanDiesSpriteClips[6].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[6].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[7].x = 224;
        gPacmanDiesSpriteClips[7].y = 384;
        gPacmanDiesSpriteClips[7].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[7].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[8].x = 256;
        gPacmanDiesSpriteClips[8].y = 384;
        gPacmanDiesSpriteClips[8].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[8].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[9].x = 288;
        gPacmanDiesSpriteClips[9].y = 384;
        gPacmanDiesSpriteClips[9].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[9].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[10].x = 320;
        gPacmanDiesSpriteClips[10].y = 384;
        gPacmanDiesSpriteClips[10].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[10].h = TILE_HEIGHT;
        
        gPacmanDiesSpriteClips[11].x = 352;
        gPacmanDiesSpriteClips[11].y = 384;
        gPacmanDiesSpriteClips[11].w = TILE_WIDTH;
        gPacmanDiesSpriteClips[11].h = TILE_HEIGHT;
        
    }
    
////////////////////////////////////////////////////////////////

//////////////////////////// FANTASMAS /////////////////////////

// Fantasma vermelho
    
    // Carrega a textura do fantasma vermelho
    if(!gBlinkyTexture.loadFromFile(&gBlinkyTexture, "../res/sprites/map_sprites.png", gRenderer)){
        printf("Falha ao carregar a textura do fantasma vermelho!\n");
        success = false;
    } else {
        
        // Seta os sprite clips do fantasma vermelho
        gBlinkySpriteClips[GHOST_DOWN][0].x = 0;
        gBlinkySpriteClips[GHOST_DOWN][0].y = 224;
        gBlinkySpriteClips[GHOST_DOWN][0].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DOWN][0].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DOWN][1].x = 32;
        gBlinkySpriteClips[GHOST_DOWN][1].y = 224;
        gBlinkySpriteClips[GHOST_DOWN][1].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DOWN][1].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_UP][0].x = 64;
        gBlinkySpriteClips[GHOST_UP][0].y = 224;
        gBlinkySpriteClips[GHOST_UP][0].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_UP][0].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_UP][1].x = 96;
        gBlinkySpriteClips[GHOST_UP][1].y = 224;
        gBlinkySpriteClips[GHOST_UP][1].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_UP][1].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_LEFT][0].x = 128;
        gBlinkySpriteClips[GHOST_LEFT][0].y = 224;
        gBlinkySpriteClips[GHOST_LEFT][0].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_LEFT][0].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_LEFT][1].x = 160;
        gBlinkySpriteClips[GHOST_LEFT][1].y = 224;
        gBlinkySpriteClips[GHOST_LEFT][1].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_LEFT][1].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_RIGHT][0].x = 192;
        gBlinkySpriteClips[GHOST_RIGHT][0].y = 224;
        gBlinkySpriteClips[GHOST_RIGHT][0].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_RIGHT][0].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_RIGHT][1].x = 224;
        gBlinkySpriteClips[GHOST_RIGHT][1].y = 224;
        gBlinkySpriteClips[GHOST_RIGHT][1].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_RIGHT][1].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DEAD_DOWN][0].x = 128;
        gBlinkySpriteClips[GHOST_DEAD_DOWN][0].y = 352;
        gBlinkySpriteClips[GHOST_DEAD_DOWN][0].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DEAD_DOWN][0].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DEAD_DOWN][1].x = 128;
        gBlinkySpriteClips[GHOST_DEAD_DOWN][1].y = 352;
        gBlinkySpriteClips[GHOST_DEAD_DOWN][1].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DEAD_DOWN][1].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DEAD_UP][0].x = 160;
        gBlinkySpriteClips[GHOST_DEAD_UP][0].y = 352;
        gBlinkySpriteClips[GHOST_DEAD_UP][0].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DEAD_UP][0].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DEAD_UP][1].x = 160;
        gBlinkySpriteClips[GHOST_DEAD_UP][1].y = 352;
        gBlinkySpriteClips[GHOST_DEAD_UP][1].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DEAD_UP][1].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DEAD_LEFT][0].x = 192;
        gBlinkySpriteClips[GHOST_DEAD_LEFT][0].y = 352;
        gBlinkySpriteClips[GHOST_DEAD_LEFT][0].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DEAD_LEFT][0].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DEAD_LEFT][1].x = 192;
        gBlinkySpriteClips[GHOST_DEAD_LEFT][1].y = 352;
        gBlinkySpriteClips[GHOST_DEAD_LEFT][1].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DEAD_LEFT][1].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DEAD_RIGHT][0].x = 224;
        gBlinkySpriteClips[GHOST_DEAD_RIGHT][0].y = 352;
        gBlinkySpriteClips[GHOST_DEAD_RIGHT][0].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DEAD_RIGHT][0].h = TILE_HEIGHT;
        
        gBlinkySpriteClips[GHOST_DEAD_RIGHT][1].x = 224;
        gBlinkySpriteClips[GHOST_DEAD_RIGHT][1].y = 352;
        gBlinkySpriteClips[GHOST_DEAD_RIGHT][1].w = TILE_WIDTH;
        gBlinkySpriteClips[GHOST_DEAD_RIGHT][1].h = TILE_HEIGHT;
        
        gGhostVulnerableSpriteClips[0].x = 0;
        gGhostVulnerableSpriteClips[0].y = 352;
        gGhostVulnerableSpriteClips[0].w = TILE_WIDTH;
        gGhostVulnerableSpriteClips[0].h = TILE_HEIGHT;
        
        gGhostVulnerableSpriteClips[1].x = 96;
        gGhostVulnerableSpriteClips[1].y = 352;
        gGhostVulnerableSpriteClips[1].w = TILE_WIDTH;
        gGhostVulnerableSpriteClips[1].h = TILE_HEIGHT;
        
        gGhostVulnerableSpriteClips[2].x = 32;
        gGhostVulnerableSpriteClips[2].y = 352;
        gGhostVulnerableSpriteClips[2].w = TILE_WIDTH;
        gGhostVulnerableSpriteClips[2].h = TILE_HEIGHT;
        
        gGhostVulnerableSpriteClips[3].x = 64;
        gGhostVulnerableSpriteClips[3].y = 352;
        gGhostVulnerableSpriteClips[3].w = TILE_WIDTH;
        gGhostVulnerableSpriteClips[3].h = TILE_HEIGHT;
    }


// Fantasma rosa
    
    // Carrega a textura do fantasma rosa
    if(!gPinkyTexture.loadFromFile(&gPinkyTexture, "../res/sprites/map_sprites.png", gRenderer)){
        printf("Falha ao carregar a textura do fantasma rosa!\n");
        success = false;
    } else {
        
        // Seta os sprite clips do fantasma rosa
        gPinkySpriteClips[GHOST_DOWN][0].x = 0;
        gPinkySpriteClips[GHOST_DOWN][0].y = 288;
        gPinkySpriteClips[GHOST_DOWN][0].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DOWN][0].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DOWN][1].x = 32;
        gPinkySpriteClips[GHOST_DOWN][1].y = 288;
        gPinkySpriteClips[GHOST_DOWN][1].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DOWN][1].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_UP][0].x = 64;
        gPinkySpriteClips[GHOST_UP][0].y = 288;
        gPinkySpriteClips[GHOST_UP][0].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_UP][0].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_UP][1].x = 96;
        gPinkySpriteClips[GHOST_UP][1].y = 288;
        gPinkySpriteClips[GHOST_UP][1].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_UP][1].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_LEFT][0].x = 128;
        gPinkySpriteClips[GHOST_LEFT][0].y = 288;
        gPinkySpriteClips[GHOST_LEFT][0].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_LEFT][0].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_LEFT][1].x = 160;
        gPinkySpriteClips[GHOST_LEFT][1].y = 288;
        gPinkySpriteClips[GHOST_LEFT][1].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_LEFT][1].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_RIGHT][0].x = 192;
        gPinkySpriteClips[GHOST_RIGHT][0].y = 288;
        gPinkySpriteClips[GHOST_RIGHT][0].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_RIGHT][0].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_RIGHT][1].x = 224;
        gPinkySpriteClips[GHOST_RIGHT][1].y = 288;
        gPinkySpriteClips[GHOST_RIGHT][1].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_RIGHT][1].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DEAD_DOWN][0].x = 128;
        gPinkySpriteClips[GHOST_DEAD_DOWN][0].y = 352;
        gPinkySpriteClips[GHOST_DEAD_DOWN][0].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DEAD_DOWN][0].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DEAD_DOWN][1].x = 128;
        gPinkySpriteClips[GHOST_DEAD_DOWN][1].y = 352;
        gPinkySpriteClips[GHOST_DEAD_DOWN][1].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DEAD_DOWN][1].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DEAD_UP][0].x = 160;
        gPinkySpriteClips[GHOST_DEAD_UP][0].y = 352;
        gPinkySpriteClips[GHOST_DEAD_UP][0].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DEAD_UP][0].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DEAD_UP][1].x = 160;
        gPinkySpriteClips[GHOST_DEAD_UP][1].y = 352;
        gPinkySpriteClips[GHOST_DEAD_UP][1].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DEAD_UP][1].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DEAD_LEFT][0].x = 192;
        gPinkySpriteClips[GHOST_DEAD_LEFT][0].y = 352;
        gPinkySpriteClips[GHOST_DEAD_LEFT][0].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DEAD_LEFT][0].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DEAD_LEFT][1].x = 192;
        gPinkySpriteClips[GHOST_DEAD_LEFT][1].y = 352;
        gPinkySpriteClips[GHOST_DEAD_LEFT][1].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DEAD_LEFT][1].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DEAD_RIGHT][0].x = 224;
        gPinkySpriteClips[GHOST_DEAD_RIGHT][0].y = 352;
        gPinkySpriteClips[GHOST_DEAD_RIGHT][0].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DEAD_RIGHT][0].h = TILE_HEIGHT;
        
        gPinkySpriteClips[GHOST_DEAD_RIGHT][1].x = 224;
        gPinkySpriteClips[GHOST_DEAD_RIGHT][1].y = 352;
        gPinkySpriteClips[GHOST_DEAD_RIGHT][1].w = TILE_WIDTH;
        gPinkySpriteClips[GHOST_DEAD_RIGHT][1].h = TILE_HEIGHT;
        
    }

// Fantasma azul
    
    // Carrega a textura do fantasma azul
    if(!gInkyTexture.loadFromFile(&gInkyTexture, "../res/sprites/map_sprites.png", gRenderer)){
        printf("Falha ao carregar a textura do fantasma azul!\n");
        success = false;
    } else {
        
        // Seta os sprite clips do fantasma azul
        gInkySpriteClips[GHOST_DOWN][0].x = 0;
        gInkySpriteClips[GHOST_DOWN][0].y = 256;
        gInkySpriteClips[GHOST_DOWN][0].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DOWN][0].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DOWN][1].x = 32;
        gInkySpriteClips[GHOST_DOWN][1].y = 256;
        gInkySpriteClips[GHOST_DOWN][1].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DOWN][1].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_UP][0].x = 64;
        gInkySpriteClips[GHOST_UP][0].y = 256;
        gInkySpriteClips[GHOST_UP][0].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_UP][0].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_UP][1].x = 96;
        gInkySpriteClips[GHOST_UP][1].y = 256;
        gInkySpriteClips[GHOST_UP][1].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_UP][1].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_LEFT][0].x = 128;
        gInkySpriteClips[GHOST_LEFT][0].y = 256;
        gInkySpriteClips[GHOST_LEFT][0].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_LEFT][0].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_LEFT][1].x = 160;
        gInkySpriteClips[GHOST_LEFT][1].y = 256;
        gInkySpriteClips[GHOST_LEFT][1].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_LEFT][1].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_RIGHT][0].x = 192;
        gInkySpriteClips[GHOST_RIGHT][0].y = 256;
        gInkySpriteClips[GHOST_RIGHT][0].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_RIGHT][0].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_RIGHT][1].x = 224;
        gInkySpriteClips[GHOST_RIGHT][1].y = 256;
        gInkySpriteClips[GHOST_RIGHT][1].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_RIGHT][1].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DEAD_DOWN][0].x = 128;
        gInkySpriteClips[GHOST_DEAD_DOWN][0].y = 352;
        gInkySpriteClips[GHOST_DEAD_DOWN][0].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DEAD_DOWN][0].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DEAD_DOWN][1].x = 128;
        gInkySpriteClips[GHOST_DEAD_DOWN][1].y = 352;
        gInkySpriteClips[GHOST_DEAD_DOWN][1].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DEAD_DOWN][1].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DEAD_UP][0].x = 160;
        gInkySpriteClips[GHOST_DEAD_UP][0].y = 352;
        gInkySpriteClips[GHOST_DEAD_UP][0].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DEAD_UP][0].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DEAD_UP][1].x = 160;
        gInkySpriteClips[GHOST_DEAD_UP][1].y = 352;
        gInkySpriteClips[GHOST_DEAD_UP][1].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DEAD_UP][1].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DEAD_LEFT][0].x = 192;
        gInkySpriteClips[GHOST_DEAD_LEFT][0].y = 352;
        gInkySpriteClips[GHOST_DEAD_LEFT][0].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DEAD_LEFT][0].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DEAD_LEFT][1].x = 192;
        gInkySpriteClips[GHOST_DEAD_LEFT][1].y = 352;
        gInkySpriteClips[GHOST_DEAD_LEFT][1].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DEAD_LEFT][1].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DEAD_RIGHT][0].x = 224;
        gInkySpriteClips[GHOST_DEAD_RIGHT][0].y = 352;
        gInkySpriteClips[GHOST_DEAD_RIGHT][0].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DEAD_RIGHT][0].h = TILE_HEIGHT;
        
        gInkySpriteClips[GHOST_DEAD_RIGHT][1].x = 224;
        gInkySpriteClips[GHOST_DEAD_RIGHT][1].y = 352;
        gInkySpriteClips[GHOST_DEAD_RIGHT][1].w = TILE_WIDTH;
        gInkySpriteClips[GHOST_DEAD_RIGHT][1].h = TILE_HEIGHT;
        
    }

// Fantasma laranja
    
    // Carrega a textura do fantasma laranja
    if(!gClydeTexture.loadFromFile(&gClydeTexture, "../res/sprites/map_sprites.png", gRenderer)){
        printf("Falha ao carregar a textura do fantasma laranja!\n");
        success = false;
    } else {
        
        // Seta os sprite clips do fantasma laranja
        gClydeSpriteClips[GHOST_DOWN][0].x = 0;
        gClydeSpriteClips[GHOST_DOWN][0].y = 320;
        gClydeSpriteClips[GHOST_DOWN][0].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DOWN][0].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DOWN][1].x = 32;
        gClydeSpriteClips[GHOST_DOWN][1].y = 320;
        gClydeSpriteClips[GHOST_DOWN][1].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DOWN][1].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_UP][0].x = 64;
        gClydeSpriteClips[GHOST_UP][0].y = 320;
        gClydeSpriteClips[GHOST_UP][0].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_UP][0].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_UP][1].x = 96;
        gClydeSpriteClips[GHOST_UP][1].y = 320;
        gClydeSpriteClips[GHOST_UP][1].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_UP][1].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_LEFT][0].x = 128;
        gClydeSpriteClips[GHOST_LEFT][0].y = 320;
        gClydeSpriteClips[GHOST_LEFT][0].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_LEFT][0].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_LEFT][1].x = 160;
        gClydeSpriteClips[GHOST_LEFT][1].y = 320;
        gClydeSpriteClips[GHOST_LEFT][1].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_LEFT][1].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_RIGHT][0].x = 192;
        gClydeSpriteClips[GHOST_RIGHT][0].y = 320;
        gClydeSpriteClips[GHOST_RIGHT][0].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_RIGHT][0].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_RIGHT][1].x = 224;
        gClydeSpriteClips[GHOST_RIGHT][1].y = 320;
        gClydeSpriteClips[GHOST_RIGHT][1].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_RIGHT][1].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DEAD_DOWN][0].x = 128;
        gClydeSpriteClips[GHOST_DEAD_DOWN][0].y = 352;
        gClydeSpriteClips[GHOST_DEAD_DOWN][0].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DEAD_DOWN][0].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DEAD_DOWN][1].x = 128;
        gClydeSpriteClips[GHOST_DEAD_DOWN][1].y = 352;
        gClydeSpriteClips[GHOST_DEAD_DOWN][1].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DEAD_DOWN][1].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DEAD_UP][0].x = 160;
        gClydeSpriteClips[GHOST_DEAD_UP][0].y = 352;
        gClydeSpriteClips[GHOST_DEAD_UP][0].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DEAD_UP][0].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DEAD_UP][1].x = 160;
        gClydeSpriteClips[GHOST_DEAD_UP][1].y = 352;
        gClydeSpriteClips[GHOST_DEAD_UP][1].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DEAD_UP][1].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DEAD_LEFT][0].x = 192;
        gClydeSpriteClips[GHOST_DEAD_LEFT][0].y = 352;
        gClydeSpriteClips[GHOST_DEAD_LEFT][0].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DEAD_LEFT][0].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DEAD_LEFT][1].x = 192;
        gClydeSpriteClips[GHOST_DEAD_LEFT][1].y = 352;
        gClydeSpriteClips[GHOST_DEAD_LEFT][1].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DEAD_LEFT][1].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DEAD_RIGHT][0].x = 224;
        gClydeSpriteClips[GHOST_DEAD_RIGHT][0].y = 352;
        gClydeSpriteClips[GHOST_DEAD_RIGHT][0].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DEAD_RIGHT][0].h = TILE_HEIGHT;
        
        gClydeSpriteClips[GHOST_DEAD_RIGHT][1].x = 224;
        gClydeSpriteClips[GHOST_DEAD_RIGHT][1].y = 352;
        gClydeSpriteClips[GHOST_DEAD_RIGHT][1].w = TILE_WIDTH;
        gClydeSpriteClips[GHOST_DEAD_RIGHT][1].h = TILE_HEIGHT;
        
    }


////////////////////////////////////////////////////////////////

//////////////////////////// TILES /////////////////////////////

    // Carrega a textura dos tiles
    if(!gTileTexture.loadFromFile(&gTileTexture, "../res/sprites/map_sprites.png", gRenderer)){
        printf("Falha ao carregar a textura dos tiles!\n");
        success = false;
    }
    
    // Carrega o mapa de tiles
    gTotalPills = setTiles(tiles, gTileClips);
    if(!gTotalPills){
        printf("Falha ao carregar o mapa de tiles!\n");
        success = false;
    }

////////////////////////////////////////////////////////////////

//////////////////////////// MUSICAS ///////////////////////////

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

//////////////////////////////////////////////////////////////

    return success;
}