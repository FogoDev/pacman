#include "init.h"

bool init()
{
    // Inicializando a flag
    bool success = true;
    
    // Inicializando o SDL
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
        printf("O SDL não conseguiu inicializar! SDL_Error: %s\n", SDL_GetError());
        success = false;
        
    } else {
        
        // Seta o filtro de texture para linear
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
            printf("Aviso: Filtro de textura linear não ativado!");
        }
 
        // Cria a janela
        gWindow = SDL_CreateWindow("The C Coded Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(!gWindow){
            printf("A janela não pôde ser criada! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            // Cria o renderizador para a janela
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if(!gRenderer){
                printf("O Renderizador não pôde ser criado! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                // Inicializa a cor do renderizador
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                
                // Inicializa o carregamento de PNG
                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) & imgFlags)){
                    printf("SDL_image não pode ser inicializado! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                
                // Inicializa o SDL_ttf
                if(TTF_Init() == -1){
                    printf("SDL_ttf não pode ser inicializado! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
                
                // Inicializa o SDL_mixer
                if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 && Mix_Init(MIX_INIT_MP3)){
                    printf("SDL_mixer não pode ser inicializado! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }
                
                // Inicializa os objetos de textura                
                //Texture_object_new(&gButtonSpriteSheetTexture);
                // for(int i = 0; i < TOTAL_BUTTONS; i++){
                //     Button_object_new(&(gButtons[i]));  
                // }
                
                
                // Texture_object_new(&gPromptTextTexture);
                // for(int i = 0; i < TOTAL_DATA; i++){
                //     Texture_object_new(&gDataTexture[i]);
                // }
                
                
                // Inicializa textura dos tiles
                Texture_object_new(&gTileTexture);

                // Inicializa texturas de texto do jogo
                Texture_object_new(&gScoreTextTexture);
                Texture_object_new(&gPointsTextTexture);
                Texture_object_new(&gLivesTextTexture);
                
                // Inicializa textura do desenvolvedor 
                Texture_object_new(&gDevTextTexture);
                
                // Inicializa texturas da tela inicial 
                Texture_object_new(&gPacmanLogoTexture);
                Texture_object_new(&gPressEnterTextTexture);
                
                // Inicializa textura de novo nível
                Texture_object_new(&gNewLevelTextTexture);
                
                // Inicializa textura de game over
                Texture_object_new(&gGameOverTextTexture);
                
                // Inicializa os temporizadores
                Time_object_new(&fpsTimer);
                Time_object_new(&capTimer);
                
                
                // Inicializa o pacman
                Dot_object_new(&gPacman, 32, 384, false);
                
                // Inicializa textura do pacman
                Texture_object_new(&gPacmanTexture);
                
                //Inicializa os fantasmas
                Dot_object_new(&gBlinky, 9 * 32, 384, true);
                Dot_object_new(&gPinky, 10 * 32, 384, true);
                Dot_object_new(&gInky, 11 * 32, 384, true);
                Dot_object_new(&gClyde, 12 * 32, 384, true);
                
                // Inicializa as texturas dos fantasmas
                Texture_object_new(&gBlinkyTexture);
                Texture_object_new(&gPinkyTexture);
                Texture_object_new(&gInkyTexture);
                Texture_object_new(&gClydeTexture);
                   
            }
        }
    }
    
    return success;
}