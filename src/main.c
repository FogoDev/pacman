#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string.h>
#include "constantsNdefines.h"
#include "init.h"
#include "loadMedia.h"
#include "closeProgram.h"
#include "globals.h"
#include "textureObject.h"
#include "buttonObject.h"
#include "timeObject.h"
#include "dotObject.h"
#include "tileObject.h"
#include "checkCollision.h"


int main (int argc, char **argv)
{
    // Inicia o SDL e cria a janela
    if(!init()){
        printf("Falha ao inicializar!\n");
    } else {
        // Carrega a midia
        if(!loadMedia(tileSet, gTileClips)){
            printf("Falha ao carregar a midia!\n");
        } else {
            // Flag do loop principal 
            bool quit = false;
            
            // Manipulador de eventos do SDL
            SDL_Event e;
            
            // Modularizando os componentes das cores
            // uint8_t r = 255;
            // uint8_t g = 255;
            // uint8_t b = 255;
            
            // // Modularizando o alpha
            // uint8_t a = 255;
            
            // // Frame atual da animação
            // int frame = 0;
            
            
            // // Tipo de flip
            // SDL_RendererFlip flipType = SDL_FLIP_NONE;
            
            // Texture_object currentTexture;
            // Texture_object_new(&currentTexture);
            
            
            // Variáveis do jogo
            bool gameStarted = false;
            int lives = 3;
            uint8_t devTextAlpha = 255;
            
            // Seta a cor do texto
			SDL_Color textColor = { 0xFF, 0xFF, 0xFF, 0xFF };
            // SDL_Color highlightColor = {0xFF, 0, 0, 0xFF};
            
            // // Ponto de input atual
            // int currentData = 0;
            
            // Começa a contar os frames per second
            int countedFrames = 0;
            fpsTimer.start(&fpsTimer);
  
            
            // A entrada de texto atual
            // char *inputText = (char *) malloc(11 * sizeof(char)); 
            // memset(inputText, '\0', sizeof(char));
            char scoreBuffer[21];
            memset(scoreBuffer, '\0', sizeof(char) * 21);       
            sprintf(scoreBuffer, "%llu", gScore);
            gPointsTextTexture.loadFromRenderedText(&gPointsTextTexture, scoreBuffer, textColor, gRenderer, gFont);
            
            int playingWaka = 0;
            int stopPlayingWaka = 0;
            
            // // Ativa a entrada de texto do SDL
            // SDL_StartTextInput();
  
            // Enquanto a aplicacao estiver rodando
            while(!quit){
                
                // // A flag do renderizador de texto
                // bool renderText = false;
                
                
                // Inicia o temporizador pra limitar o fps
                capTimer.start(&capTimer);
                
                // Manipula os eventos na fila
                while(SDL_PollEvent(&e) != 0){
                    // Usuario requisitou fechamento do programa
                    if(e.type == SDL_QUIT){
                        quit = true;
                    } 
                    
                    else if(!gameStarted){
                        if(e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_KP_ENTER){
                            gameStarted = 1;
                            Mix_HaltChannel(2);
                            Mix_PlayChannel(0, gOpeningSoundEffect, 1);
                            
                        }
                    }
                    // else if(e.type == SDL_KEYDOWN){
                    //     // Manipula backspace
                    //     // if(e.key.keysym.sym == SDLK_BACKSPACE && strlen(inputText) > 0){
                    //     //     // Tira fora o último caractere
                    //     //     inputText[strlen(inputText) -1] = '\0';
                    //     //     renderText = true;
                    //     // }
                    //     char buffer[13];
                    //     switch(e.key.keysym.sym){
                    //         // A entrada de cima
                    //         case SDLK_UP:
                    //             // Rerenderiza a entrada anterior
                    //             memset(buffer, '\0', sizeof(char) * 13);
                    //             sprintf(buffer, "%d", gData[currentData]);
                    //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, textColor, gRenderer, gFont );
                    //             currentData--;
                    //             if(currentData < 0) currentData = TOTAL_DATA -1;
                                
                    //             // Rerenderiza a entrada atual
                    //             memset(buffer, '\0', sizeof(char) * 13);
                    //             sprintf(buffer, "%d", gData[currentData]);
                    //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, highlightColor, gRenderer, gFont );
                                
                    //             break;
                            
                    //         // A entrada de baixo
                    //         case SDLK_DOWN:
                    //             // Rerenderiza a entrada anterior
                    //             memset(buffer, '\0', sizeof(char) * 13);
                    //             sprintf(buffer, "%d", gData[currentData]);
                    //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, textColor, gRenderer, gFont );
                    //             currentData++;
                    //             if(currentData == TOTAL_DATA) currentData = 0;
                                
                    //             // Rerenderiza a entrada atual
                    //             memset(buffer, '\0', sizeof(char) * 13);
                    //             sprintf(buffer, "%d", gData[currentData]);
                    //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, highlightColor, gRenderer, gFont );
                                
                    //             break;
                                
                            
                    //         // Decrementa o valor da entrada
                    //         case SDLK_LEFT:
                    //             gData[currentData]--;
                    //             memset(buffer, '\0', sizeof(char) * 13);
                    //             sprintf(buffer, "%d", gData[currentData]);
                    //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, highlightColor, gRenderer, gFont );
                    //             break;
                                
                    //         // Incrementa o valor da entrada
                    //         case SDLK_RIGHT:
                    //             gData[currentData]++;
                    //             memset(buffer, '\0', sizeof(char) * 13);
                    //             sprintf(buffer, "%d", gData[currentData]);
                    //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, highlightColor, gRenderer, gFont );
                    //             break;
                                
                    //     }
                    // }
                    
                    // // Evento de inserção de texto
                    // else if(e.type == SDL_TEXTINPUT){
                    //     // Não sendo um copiar e colar
                    //     if(!((e.text.text[0] == 'c' || e.text.text[0] == 'C') && (e.text.text[0] == 'v' || e.text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL) && strlen(inputText) < 10){
                    //         // Concatena o caractere
                    //         strcat(inputText, e.text.text);
                    //         renderText = true;
                    //     }
                    // }
                    
                    // Manipula os inputs para o ponto
                    if(gameStarted) gPacman.handleEvent(&gPacman, &e);
                    
                    // else if(e.type == SDL_KEYDOWN){
                        
                    //     // Start / stop do temporizador
                    //     if(e.key.keysym.sym == SDLK_s){
                    //         if(gTime.mStarted){
                    //             gTime.stop(&gTime);
                    //         } else {
                    //             gTime.start(&gTime);
                    //         }
                    //     } 
                    //     // Pausa / Despausa o temporizador
                    //     else if(e.key.keysym.sym == SDLK_p){
                    //         if(gTime.mStarted && gTime.mPaused){
                    //             gTime.unpause(&gTime);
                    //         } else {
                    //             gTime.pause(&gTime);
                    //         }
                    //     }
                        
                    //     switch(e.key.keysym.sym){
                    //         // Toca o efeito sonoro High
                    //         case SDLK_1:
                    //             Mix_PlayChannel(-1, gHigh, 0);
                    //             break;
                            
                    //         // Toca o efeito sonoro medium
                    //         case SDLK_2:
                    //             Mix_PlayChannel(-1, gMedium, 0);
                    //             break;
                                
                    //         // Toca o efeito sonoro low
                    //         case SDLK_3:
                    //             Mix_PlayChannel(-1, gLow, 0);
                    //             break;
                                
                    //         // Toca o efeito sonoro scratch
                    //         case SDLK_4:
                    //             Mix_PlayChannel(-1, gScratch, 0);
                    //             break;
                                
                    //         case SDLK_9:
                    //             // Se nenhuma música estiver tocando
                    //             if(Mix_PlayingMusic() == 0){
                    //                 // Toca a música
                    //                 Mix_PlayMusic(gMusic, -1);
                    //             } else {
                    //                 // Se a música estiver pausada
                    //                 if(Mix_PausedMusic() == 1){
                    //                     // Despausa a música
                    //                     Mix_ResumeMusic();    
                    //                 } else {
                    //                     Mix_PauseMusic();
                    //                 }
                    //             }
                    //             break;
                            
                    //         case SDLK_0:
                    //             // Para a música
                    //             Mix_HaltMusic();
                    //             break;
                    //     }
                    // }
                }
                          
                
                // Calcula e corrige o FPS
                float avgFPS = countedFrames / (fpsTimer.getTicks(&fpsTimer) / 1000.0);
                if(avgFPS > 2000000){
                    avgFPS = 0;
                }
                
                // Captura a posição do pacman antes de movê-lo
                int lastX = gPacman.mPosX;
                int lastY = gPacman.mPosY;

                // Move o ponto
                gPacman.move(&gPacman, tileSet);
                for (int i = 0; i < TOTAL_TILES; i++){
                    if(eatPill(gPacman.mCollider, tileSet[i]->mBox)){
                        if(tileSet[i]->mType == 1 || tileSet[i]->mType == 2){
                            if(!Mix_Playing(1)) {
                                Mix_PlayChannel( 1, gWakaWakaSoundEffect, -1);
                                playingWaka = 1;
                                stopPlayingWaka = 0;
                            }
                        }
                        
                        if(tileSet[i]->mType == 1){
                            gScore += 10;
                        } else if(tileSet[i]->mType == 2){
                            gScore += 100;
                        }
                        
                        
                        tileSet[i]->mType = 0;
                    }
                }
                
                if(playingWaka){
                    if(stopPlayingWaka){
                        Mix_HaltChannel(1);
                        playingWaka = 0;    
                    } 
                    
                } 
                
                // Posiciona o ângulo que o pacman vai ser renderizado de acordo com o movimento que ele fez 
                if(lastX < gPacman.mPosX) gPacman.mDirection = 0;
                else if(lastX > gPacman.mPosX) gPacman.mDirection = 180;
                else if(lastY < gPacman.mPosY) gPacman.mDirection = 90;
                else if(lastY > gPacman.mPosY) gPacman.mDirection = 270;
                else {
                    pacmanFrame = 0;
                    stopPlayingWaka = 1;
                }
                
                // // Renderiza o texto se for preciso
                // if(renderText){
                //     // Texto não está vazio
                //     if(strlen(inputText) > 0){
                //         // Renderiza o novo texto
                //         gInputTextTexture.loadFromRenderedText(&gInputTextTexture, inputText, textColor, gRenderer, gFont);
                //     } else {
                //         // Renderiza o espaço na textura
                //         gInputTextTexture.loadFromRenderedText(&gInputTextTexture, " ", textColor, gRenderer, gFont);
                //     }
                // }
                
                // Limpa o renderizador
                SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
                SDL_RenderClear(gRenderer);
                
                
                if(gameStarted){
                    if(!Mix_Playing(3) && !Mix_Playing(0)) Mix_PlayChannel(3, gSirenMusic, -1);
                    // Renderiza o mapa
                    for(int i = 0; i < TOTAL_TILES; i++){
                        gTileTexture.render(&gTileTexture, tileSet[i]->mBox.x, tileSet[i]->mBox.y, gRenderer, &(gTileClips[tileSet[i]->mType]), 0.0, NULL, SDL_FLIP_NONE);
                        // tileSet[i]->render(tileSet[i], &gTileTexture, gRenderer, gTileClips);
                    }
                    
                    // Renderiza o pacman
                    SDL_Rect *currentPacmanClip = &gPacmanSpriteClips[pacmanFrame / PACMAN_WALKING_SPRITES];
                    gPacman.render(&gPacman, &gPacmanTexture, gRenderer, currentPacmanClip, gPacman.mDirection);
                    
                                
                    // Renderiza as texturas de texto
                    gScoreTextTexture.render(&gScoreTextTexture, TILE_WIDTH / 2, TILE_HEIGHT / 2, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    
                    memset(scoreBuffer, '\0', sizeof(char) * 21);       
                    sprintf(scoreBuffer, "%llu", gScore);
                    gPointsTextTexture.loadFromRenderedText(&gPointsTextTexture, scoreBuffer, textColor, gRenderer, gFont);
                    
                    gPointsTextTexture.render(&gPointsTextTexture, gScoreTextTexture.mWidth + TILE_WIDTH , TILE_HEIGHT / 2, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    
                    gLivesTextTexture.render(&gLivesTextTexture, TILE_WIDTH / 2, SCREEN_HEIGHT - (7* TILE_HEIGHT) /6, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    for(int i = 0; i < lives; i++){
                        gPacmanTexture.render(&gPacmanTexture, TILE_WIDTH + gLivesTextTexture.mWidth + ((5 * TILE_WIDTH / 4) * i), SCREEN_HEIGHT -  TILE_HEIGHT -2, gRenderer, &gPacmanSpriteClips[2], 0.0, NULL, SDL_FLIP_NONE);
                    }
                    
                    // for(int i = 0; i < TOTAL_DATA; i++){
                    //     gDataTexture[i].render(&gDataTexture[i], (SCREEN_WIDTH - gDataTexture[i].mWidth) / 2, gScoreTextTexture.mHeight + gDataTexture[0].mHeight * i, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    // }
                
                } else {
                    if(!Mix_Playing(2)) Mix_PlayChannel(2, gIntermissionMusic, -1);
                    gPacmanLogoTexture.render(&gPacmanLogoTexture, (SCREEN_WIDTH - gPacmanLogoTexture.mWidth) / 2, SCREEN_HEIGHT / 4, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    gPressEnterTextTexture.render(&gPressEnterTextTexture, (SCREEN_WIDTH - gPressEnterTextTexture.mWidth) / 2, 3 * SCREEN_HEIGHT / 4 , gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    gDevTextTexture.setAlpha(&gDevTextTexture, devTextAlpha);
                    if(devTextAlpha > 0) SDL_RenderClear(gRenderer);
                    gDevTextTexture.render(&gDevTextTexture, (SCREEN_WIDTH - gDevTextTexture.mWidth) / 2, SCREEN_HEIGHT / 2 , gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    if(devTextAlpha > 0) SDL_Delay(10);
                    if(devTextAlpha > 0) devTextAlpha--;
                    if(devTextAlpha < 0) devTextAlpha = 0;
                }
                
                
                // Atualiza a tela
                SDL_RenderPresent(gRenderer);
                countedFrames++;
                
                // Vai para o próximo frame do Pacman
                pacmanFrame++;
                
                // Circula a animação do Pacman
                if(pacmanFrame / PACMAN_WALKING_SPRITES >= PACMAN_WALKING_SPRITES) pacmanFrame = 0;
                
                // Se o frame terminar cedo
                int frameTicks = capTimer.getTicks(&capTimer);
                if(frameTicks < SCREEN_TICKS_PER_FRAME){
                    // Espera o tempo restante
                    SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
                }
                // Desabilita o input de texto
                // SDL_StopTextInput();
                // if(inputText) free(inputText);
            }
        }
    }
    
    // Libera os recursos e fecha o SDL
    closeProgram(tileSet);
        
    return 0;
}