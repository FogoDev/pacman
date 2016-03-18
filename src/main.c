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
#include "timeObject.h"
#include "dotObject.h"
#include "tileObject.h"
#include "checkCollision.h"


int main (int argc, char **argv)
{
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* INICIALIZA AS FUNÇÕES INTERNAS DO SDL E DO JOGO EM SI */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    // Inicia o SDL e cria a janela
    if(!init()){
        printf("Falha ao inicializar!\n");
    } else {
        // Carrega a midia
        if(!loadMedia(tileSet, gTileClips)){
            printf("Falha ao carregar a midia!\n");
        } else {
            
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
/* INICIALIZA AS VARIÁVEIS QUE SERÃO USADAS PRAS MECÂNICAS DA APLICAÇÃO, DO JOGO E DAS RENDERIZAÇÕES: 
|       VARIÁVEL DE CONTROLE DO MAIN LOOP
|       VARIÁVEL DE CAPTAÇÃO DE EVENTOS
|       VIDAS INICIAIS DO JOGADOR
|       VALOR DE ALPHA PARA O FADE OUT DO TEXTO DE DESENVOLVEDOR
|       VARIÁVEL PRA GUARDAR O FRAME DO PACMAN A SER RENDERIZADO
|       VARIÁVEIS PRA GUARDAR OS FRAMES DOS FANTASMAS
|       VARIÁVEL PRA CONTAR A QUANTIDADE DE PILLS RESTANTES PRA PASSAR DE NÍVEL SE FOR O CASO
|       FLAG DE PRIMEIRO NÍVEL
|       CONTROLE PARA A AQUISIÇÃO DE VIDAS EXTRAS A CADA 5000 PONTOS
|       CONTROLE PRO CASO DO PACMAN TER COMIDO UM POWER UP
|       TEMPORIZADOR PRA DESATIVAR OS EFEITOS DE POWER UP
|       INICIALIZAR A COR DOS TEXTOS RENDERIZADOR
|       INICIALIZAR AS MECÂNICAS DE CONTROLE DE FRAMERATE
|       VARIÁVEIS DE BUFFER PARA TEXTOS DINÂMICOS
|       VARIÁVEIS DE CONTROLE PRA EXECUÇÃO DO SOM DE WAKA WAKA
|       VERIFICA SE O PACMAN MORREU
|       TIMER DE TEMPO DE MORTE PROS FANTASMAS
*/
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            srand(time(NULL));
            
            // Flag do loop principal 
            bool quit = false;
            
            // Manipulador de eventos do SDL
            SDL_Event e;
             
            // Variáveis do controle de inicio de jogo
            bool gameStarted = false;
            
            // Vidas que o jogador começa
            int lives = STARTER_LIVES;
            
            // Inicializa o valor do alpha pra usar no fade out do texto do desenvolvedor
            uint8_t devTextAlpha = 255;
            
            // Frames de sprites do pacman
            int pacmanFrame = 0;
            
            // Frames de sprite dos fantasmas
            int ghostFrame = 0;
            int ghostVulnerableFrame = 0;
            
            // Pills ou powerups restantes no mapa
            int pillsLeft = gTotalPills;
            
            // Variável de controle pra caso seja o primeiro nível renderizar a tela de primeiro nível
            bool firstLevel = true;
            
            // Variável pra controle de vidas ganhas em relação ao score do jogador
            int gotLive = 1;
            
            // Variável de controle pro caso do pacman comer um power up
            bool gotPowerUp = false;
            
            // Contador de tempo pra desativar o power up;
            Uint32 powerUpTimer = 0;
            
            // Seta a cor do texto a ser usado nas renderizações
			SDL_Color textColor = { 0xFF, 0xFF, 0xFF, 0xFF };
            
            // Começa a contar os frames per second pra fazer a limitação de framerates
            int countedFrames = 0;
            fpsTimer.start(&fpsTimer);
  
            
            // Variáveis pra servirem de buffer pra pontuação do jogador e pra renderização da contagem de níveis passados
            char scoreBuffer[21];
            char newLvlbuffer[15];
            
            // Variáveis de controle pra tocar ou parar o som de waka waka ao comer as pills
            bool playingWaka = false;
            bool stopPlayingWaka = false;
            
            // Verifica se o pacman morreu
            bool pacmanDead = false;
            
            // Timers de tempos de morte dos fantasmas
            Uint32 blinkyDeadTimer;
            Uint32 pinkyDeadTimer;
            Uint32 inkyDeadTimer;
            Uint32 clydeDeadTimer;
            
            // Variável de frames da morte do pacman
            int pacmanDeadFrame = 0;
            
        /* Não ta servindo pra nada isso aqui ainda, pretendo usar pra salvar as melhores pontuações
         |   // // Ponto de input atual
         |   // int currentData = 0;
         |   // A entrada de texto atual
         |   // char *inputText = (char *) malloc(11 * sizeof(char)); 
         |   // memset(inputText, '\0', sizeof(char));
         |   
         |   // // Ativa a entrada de texto do SDL
         |   // SDL_StartTextInput();
         |
         */


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* COMEÇO DO MAIL LOOP DO JOGO E COLETOR DE EVENTOS 
|       INICIALIZA O TIMER PARA FAZER A LIMITAÇÃO DO FRAMERATE
|       VERIFICA SE O JOGADOR FECHOU A JANELA PARA ENCERRAR O PROGRAMA
|       VERIFICA SE O JOGADOR APERTOU ENTER PARA COMEÇAR A JOGAR, EM CASO POSITIVO, MARCA O JOGO PRA SER INICIADO, PÁRA A MÚSICA DA TELA INICIAL E EXECUTA A MÚSICA DE ABERTURA
|       SE O JOGO FOR INICIADO, COMEÇA A CAPTURAR OS EVENTOS DO PACMAN
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

  
            // Enquanto a aplicacao estiver rodando
            while(!quit){
                
                // // A flag do renderizador de texto
                // bool renderText = false;
                
                
                // Inicia o temporizador pra limitar o fps
                capTimer.start(&capTimer);
       
                // Manipula os eventos na fila
                while(SDL_PollEvent(&e) != false){
                    // Usuario requisitou fechamento do programa
                    if(e.type == SDL_QUIT){
                        quit = true;
                    } 
                    
                    else if(!gameStarted){
                        if(e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_KP_ENTER){
                            gameStarted = true;
                            Mix_HaltChannel(CHANNEL_TWO);
                            Mix_PlayChannel(CHANNEL_ZERO, gOpeningSoundEffect, LOOP_ONCE);
                        }
                    }
                    
                    
                    
               /* Não ta servindo pra nada isso aqui ainda, pretendo usar pra salvar as melhores pontuações
               |     // else if(e.type == SDL_KEYDOWN){
               |     //     // Manipula backspace
               |     //     // if(e.key.keysym.sym == SDLK_BACKSPACE && strlen(inputText) > 0){
               |     //     //     // Tira fora o último caractere
               |     //     //     inputText[strlen(inputText) -1] = '\0';
               |     //     //     renderText = true;
               |     //     // }
               |     //     char buffer[13];
               |     //     switch(e.key.keysym.sym){
               |     //         // A entrada de cima
               |     //         case SDLK_UP:
               |     //             // Rerenderiza a entrada anterior
               |     //             memset(buffer, '\0', sizeof(char) * 13);
               |     //             sprintf(buffer, "%d", gData[currentData]);
               |     //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, textColor, gRenderer, gFont );
               |     //             currentData--;
               |     //             if(currentData < 0) currentData = TOTAL_DATA -1;
               |                 
               |     //             // Rerenderiza a entrada atual
               |     //             memset(buffer, '\0', sizeof(char) * 13);
               |     //             sprintf(buffer, "%d", gData[currentData]);
               |     //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, highlightColor, gRenderer, gFont );
               |                 
               |     //             break;
               |             
               |     //         // A entrada de baixo
               |     //         case SDLK_DOWN:
               |     //             // Rerenderiza a entrada anterior
               |     //             memset(buffer, '\0', sizeof(char) * 13);
               |     //             sprintf(buffer, "%d", gData[currentData]);
               |     //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, textColor, gRenderer, gFont );
               |     //             currentData++;
               |     //             if(currentData == TOTAL_DATA) currentData = 0;
               |                 
               |     //             // Rerenderiza a entrada atual
               |     //             memset(buffer, '\0', sizeof(char) * 13);
               |     //             sprintf(buffer, "%d", gData[currentData]);
               |     //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, highlightColor, gRenderer, gFont );
               |                 
               |     //             break;
               |                 
               |             
               |     //         // Decrementa o valor da entrada
               |     //         case SDLK_LEFT:
               |     //             gData[currentData]--;
               |     //             memset(buffer, '\0', sizeof(char) * 13);
               |     //             sprintf(buffer, "%d", gData[currentData]);
               |     //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, highlightColor, gRenderer, gFont );
               |     //             break;
               |                 
               |     //         // Incrementa o valor da entrada
               |     //         case SDLK_RIGHT:
               |     //             gData[currentData]++;
               |     //             memset(buffer, '\0', sizeof(char) * 13);
               |     //             sprintf(buffer, "%d", gData[currentData]);
               |     //             gDataTexture[currentData].loadFromRenderedText(&gDataTexture[currentData], buffer, highlightColor, gRenderer, gFont );
               |     //             break;
               |                 
               |     //     }
               |     // }
               |     
               |     // // Evento de inserção de texto
               |     // else if(e.type == SDL_TEXTINPUT){
               |     //     // Não sendo um copiar e colar
               |     //     if(!((e.text.text[0] == 'c' || e.text.text[0] == 'C') && (e.text.text[0] == 'v' || e.text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL) && strlen(inputText) < 10){
               |     //         // Concatena o caractere
               |     //         strcat(inputText, e.text.text);
               |     //         renderText = true;
               |     //     }
               |     // }
               |     
               */

                    // Manipula os inputs para o pacman
                    if(gameStarted && !pacmanDead) gPacman.handleEvent(&gPacman, &e);

                }
                

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                
                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* VERIFICA A PONTUAÇÃO ATUAL DO JOGADOR PARA LHE CONFERIR UMA VIDA EXTRA A CADA 5000 PONTOS */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                
                // Aumenta uma vida pro pacman a cada 5000 pontos
                if(gScore / (EXTRA_LIVE_SCORE * gotLive)){
                    Mix_PlayChannel(ANY_CHANNEL, gExtraLiveSoundEffect, ONE_TIME);
                    gotLive++;
                    lives++;
                }
                
                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* EXECUTA AS MECÂNICA DE MOVIMENTAÇÃO DO PACMAN:
|       PRIMEIRO PEGA AS POSIÇÕES ANTIGAS DO PACMAN, NOS EIXOS X E Y
|       EXECUTA O MOVIMENTO DO PACMAN COM OS SEGUINTES DETALHES:
|                CASO ELE PASSE POR CIMA DE UM PILL OU POWER UP, É EXECUTADO O SOM DE WAKA WAKA COM AS DEVIDAS MECÂNICAS PRO SOM SER CONSTANTE
|                CASO O PACMAN COMA UMA PILL, AUMENTA O SCORE EM 10 PONTOS E MARCA O TILE PRA SER RESTAURADO QUANDO O NÍVEL ACABAR
|                CASE O PACMAN COMA UM POWER UP, EXECUTA AS MECÂNICAS DE POWERUP, AUMENTA O SCORE EM 100 PONTOS E MARCA O TILE PRA SER RESTAURADO QUANDO O NÍVEL ACABAR
|                MARCA O TILE COMIDO PRA FICAR VAZIO
|       EXECUTA AS MECÂNICAS PRA PARAR O SOM DE WAKA WAKA SE O PACMAN PARAR DE COMER PILLS
|       VERIFICA AS NOVAS POSIÇÕES EM RELAÇÃO AS ANTIGAS PRA DEFINIR A DIREÇÃO QUE O PACMAN SERÁ RENDERIZADO E PRA PARAR A MÚSICA WAKA WAKA CASO NECESSÁRIO
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                // Captura a posição do pacman antes de movê-lo
                int pacmanLastX = gPacman.mBox.x;
                int pacmanLastY = gPacman.mBox.y;
                

                // Move o ponto tocando a música e comendo as pills
                gPacman.move(&gPacman, tileSet);
                for (int i = 0; i < TOTAL_TILES; i++){
                    if(eat(gPacman.mBox, tileSet[i]->mBox)){
                        if(tileSet[i]->mType == TILE_PILL || tileSet[i]->mType == TILE_POWERUP){
                            if(!Mix_Playing(CHANNEL_ONE)) {
                                Mix_PlayChannel( CHANNEL_ONE, gWakaWakaSoundEffect, CONTINUOUS_LOOP);
                                playingWaka = true;
                                stopPlayingWaka = false;
                            }
                        }
                        
                        if(tileSet[i]->mType == TILE_PILL){
                            gScore += PILLSCORE;
                            tileSet[i]->mRestore = TILE_PILL;
                            pillsLeft--;
                        } else if(tileSet[i]->mType == TILE_POWERUP){
                            gScore += POWERUPSCORE;
                            tileSet[i]->mRestore = TILE_POWERUP;
                            gotPowerUp = true;
                            powerUpTimer = SDL_GetTicks();
                            pillsLeft--;
                        }                    
                        tileSet[i]->mType = TILE_PATH;
                    }
                }
                
                if(playingWaka){
                    if(stopPlayingWaka){
                        Mix_HaltChannel(CHANNEL_ONE);
                        playingWaka = false;    
                    } 
                    
                } 
                
                // Posiciona o ângulo que o pacman vai ser renderizado de acordo com o movimento que ele fez 
                if(pacmanLastX < gPacman.mBox.x) gPacman.mDirection = PACMAN_RIGHT;
                else if(pacmanLastX > gPacman.mBox.x) gPacman.mDirection = PACMAN_LEFT;
                else if(pacmanLastY < gPacman.mBox.y) gPacman.mDirection = PACMAN_DOWN;
                else if(pacmanLastY > gPacman.mBox.y) gPacman.mDirection = PACMAN_UP;
                else {
                    pacmanFrame = 0;
                    stopPlayingWaka = true;
                }

                // Desliga o power up após 5 segundos
                if(gotPowerUp){
                    if(SDL_GetTicks() - powerUpTimer >= 5000) {
                        gotPowerUp = false;
                    }
                }
                
                
                // Verifica se o pacman tem powerup pra checar a colisão com os fantasmas;
                if(gotPowerUp){
                    if(eat(gPacman.mBox, gBlinky.mBox)){
                        if(!gBlinky.mDead){
                            gBlinky.mDead = true;
                            gScore += 200;
                            blinkyDeadTimer = SDL_GetTicks();
                            Mix_PlayChannel(ANY_CHANNEL, gEatingGhostSoundEffect, ONE_TIME);
                        }
                    }
                    if(eat(gPacman.mBox, gPinky.mBox)){
                        if(!gPinky.mDead){
                            gPinky.mDead = true;
                            gScore += 200;
                            pinkyDeadTimer = SDL_GetTicks();
                            Mix_PlayChannel(ANY_CHANNEL, gEatingGhostSoundEffect, ONE_TIME);
                        }
                    }
                    if(eat(gPacman.mBox, gInky.mBox)){
                        if(!gInky.mDead){
                            gInky.mDead = true;
                            gScore += 200;
                            inkyDeadTimer = SDL_GetTicks();
                            Mix_PlayChannel(ANY_CHANNEL, gEatingGhostSoundEffect, ONE_TIME);
                        }
                    }
                    if(eat(gPacman.mBox, gClyde.mBox)){
                        if(!gClyde.mDead){
                            gClyde.mDead = true;
                            gScore += 200;
                            clydeDeadTimer = SDL_GetTicks();
                            Mix_PlayChannel(ANY_CHANNEL, gEatingGhostSoundEffect, ONE_TIME);
                        }
                    }
                
                } else {
                    if(eat(gPacman.mBox, gBlinky.mBox)){
                        if(!pacmanDead) {
                            // Diminui uma vida
                            lives--;
                            if(!Mix_Playing(CHANNEL_FOUR)) Mix_PlayChannel(CHANNEL_FOUR, gDiesSoundEffect, ONE_TIME);
                        }
                        pacmanDead = true;
                        
                    }
                    if(eat(gPacman.mBox, gPinky.mBox)){
                        if(!pacmanDead) {
                            // Diminui uma vida
                            lives--;
                            if(!Mix_Playing(CHANNEL_FOUR)) Mix_PlayChannel(CHANNEL_FOUR, gDiesSoundEffect, ONE_TIME);
                        }
                        pacmanDead = true;
                        
                    }
                    if(eat(gPacman.mBox, gInky.mBox)){
                        if(!pacmanDead) {
                            // Diminui uma vida
                            lives--;
                            if(!Mix_Playing(CHANNEL_FOUR)) Mix_PlayChannel(CHANNEL_FOUR, gDiesSoundEffect, ONE_TIME);
                        }
                        pacmanDead = true;
                        
                    }
                    if(eat(gPacman.mBox, gClyde.mBox)){
                        if(!pacmanDead) {
                            // Diminui uma vida
                            lives--;
                            if(!Mix_Playing(CHANNEL_FOUR)) Mix_PlayChannel(CHANNEL_FOUR, gDiesSoundEffect, ONE_TIME);
                        }
                        pacmanDead = true;
                        
                    }
                }
                
                if(gBlinky.mDead) if(SDL_GetTicks() - blinkyDeadTimer >= 5000) gBlinky.mDead = false;
                if(gPinky.mDead) if(SDL_GetTicks() - pinkyDeadTimer >= 5000) gPinky.mDead = false;
                if(gInky.mDead) if(SDL_GetTicks() - inkyDeadTimer >= 5000) gInky.mDead = false;
                if(gClyde.mDead) if(SDL_GetTicks() - clydeDeadTimer >= 5000) gClyde.mDead = false;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* EXECUTA AS MECÂNICAS DE MOVIMENTAÇÃO DOS FANTASMAS:
|       PRIMEIRO PEGA AS POSIÇÕES ANTIGAS DOS FANTASMAS, NOS EIXOS X E Y
|       EXECUTA OS MOVIMENTOS DE CADA FANTASMA
|       VERIFICA A MUDANÇA DE POSIÇÃO PARA RENDERIZAR O FRAME DE ACORDO COM O MOVIMENTO
*/ 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                
                
                
            
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            
            /* Não ta servindo pra nada isso aqui ainda, pretendo usar pra salvar as melhores pontuações
             |   // // Renderiza o texto se for preciso
             |   // if(renderText){
             |   //     // Texto não está vazio
             |   //     if(strlen(inputText) > 0){
             |   //         // Renderiza o novo texto
             |   //         gInputTextTexture.loadFromRenderedText(&gInputTextTexture, inputText, textColor, gRenderer, gFont);
             |   //     } else {
             |   //         // Renderiza o espaço na textura
             |   //         gInputTextTexture.loadFromRenderedText(&gInputTextTexture, " ", textColor, gRenderer, gFont);
             |   //     }
             |   // }
             |
             */
             

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* LIMPA O RENDERIZADOR PRA COMEÇAR AS RENDERIZAÇÕES DO FRAME ATUAL */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                // Limpa o renderizador
                SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
                SDL_RenderClear(gRenderer);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* PRINCIPAIS RENDERIZAÇÕES DO JOGO:
|       PRIMEIRO VERIFICA SE É O PRIMEIRO NÍVEL DO JOGO E EXIBE A TELA DE NIVEL 1 SE FOR O CASO
|       QUANDO COMEÇA O JOGO, JÁ INICIA O SOM DE SIRENE CONSTANTE DO JOGO
|       RENDERIZA TODOS OS TILES DO JOGO, MONTANDO O MAPA
|       RENDERIZA O PACMAN DE ACORDO COM O FRAME ATUAL E DE ACORDO COM A DIREÇÃO QUE ELE ESTÁ SEGUINDO
|       RENDERIZA O TEXTOS "SCORE:" E "LIVES:"
|       RENDERIZA A PONTUAÇÃO OBTIDA PELO JOGADOR
|       RENDERIZA A QUANTIDADE DE VIDAS RESTANTES
|       RENDERIZA OS FANTASMAS
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                    
                
                    if(gameStarted){
                        
                        // Se for o primeiro nível, exibe a tela de nível 1
                        if(firstLevel) {
                            gNewLevelTextTexture.render(&gNewLevelTextTexture, (SCREEN_WIDTH - gNewLevelTextTexture.mWidth) / 2, SCREEN_HEIGHT / 2, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                            firstLevel = false;
                            SDL_RenderPresent(gRenderer);
                            SDL_Delay(NEWLVLPRESENTATION);
                            
                            
                        } else {
                            
                            if(!Mix_Playing(CHANNEL_THREE) && !Mix_Playing(CHANNEL_ZERO)) Mix_PlayChannel(CHANNEL_THREE, gSirenMusic, CONTINUOUS_LOOP);
                            // Renderiza o mapa
                            for(int i = 0; i < TOTAL_TILES; i++){
                                gTileTexture.render(&gTileTexture, tileSet[i]->mBox.x, tileSet[i]->mBox.y, gRenderer, &(gTileClips[tileSet[i]->mType]), 0.0, NULL, SDL_FLIP_NONE);
                                
                            /* POR ALGUM MOTIVO TOTALMENTE OBSCURO, ESSA LINHA DE BAIXO DÁ UM SEG FAULT, DEIXEI AQUI PRA PERGUNTAR PRO PROFESSOR
                            |   // tileSet[i]->render(tileSet[i], &gTileTexture, gRenderer, gTileClips);
                            |
                            */
                            
                            }
                            
                            
                            
                           
                                        
                            // Renderiza as texturas de texto
                            gLivesTextTexture.render(&gLivesTextTexture, TILE_WIDTH / 2, SCREEN_HEIGHT - (7* TILE_HEIGHT) /6, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                            gScoreTextTexture.render(&gScoreTextTexture, TILE_WIDTH / 2, TILE_HEIGHT / 2, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                            
                            // Renderiza os pontos obtidos até o momento
                            memset(scoreBuffer, '\0', sizeof(char) * 21);       
                            sprintf(scoreBuffer, "%llu", gScore);
                            gPointsTextTexture.loadFromRenderedText(&gPointsTextTexture, scoreBuffer, textColor, gRenderer, gFont);
                            gPointsTextTexture.render(&gPointsTextTexture, gScoreTextTexture.mWidth + TILE_WIDTH , TILE_HEIGHT / 2, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                            
                            // Renderiza a quantidade atual de vidas restantes do jogador
                            for(int i = 0; i < lives; i++){
                                gPacmanTexture.render(&gPacmanTexture, TILE_WIDTH + gLivesTextTexture.mWidth + ((5 * TILE_WIDTH / 4) * i), SCREEN_HEIGHT -  TILE_HEIGHT -2, gRenderer, &gPacmanSpriteClips[2], 0.0, NULL, SDL_FLIP_NONE);
                            }
                            
                            
                            
                            // Renderiza o fantasma vermelho
                            if(!gBlinky.mDead){
                                if(gotPowerUp){
                                    gBlinky.render(&gBlinky, &gBlinkyTexture, gRenderer, &gGhostVulnerableSpriteClips[ghostVulnerableFrame / (GHOST_VULNERABLE_SPRITES * 2)], 0.0);
                                } else {
                                    gBlinky.render(&gBlinky, &gBlinkyTexture, gRenderer, &gBlinkySpriteClips[gBlinky.mDirection][ghostFrame / (GHOSTS_WALKING_SPRITES * 4)], 0.0);
                                }
                            } else {
                                gBlinky.render(&gBlinky, &gBlinkyTexture, gRenderer, &gBlinkySpriteClips[gBlinky.mDirection + GHOST_DEAD_EFFECT][0], 0.0);
                            }
                            
                            // Renderiza o fantasma rosa
                            if(!gPinky.mDead){
                                if(gotPowerUp){
                                    gPinky.render(&gPinky, &gPinkyTexture, gRenderer, &gGhostVulnerableSpriteClips[ghostVulnerableFrame / (GHOST_VULNERABLE_SPRITES * 2)], 0.0);
                                } else {
                                    gPinky.render(&gPinky, &gPinkyTexture, gRenderer, &gPinkySpriteClips[gPinky.mDirection][ghostFrame / (GHOSTS_WALKING_SPRITES * 4)], 0.0);
                                }
                            } else {
                                gPinky.render(&gPinky, &gPinkyTexture, gRenderer, &gPinkySpriteClips[gPinky.mDirection + GHOST_DEAD_EFFECT][0], 0.0);
                            }
                            
                            // Renderiza o fantasma azul
                            if(!gInky.mDead){
                                if(gotPowerUp){
                                    gInky.render(&gInky, &gInkyTexture, gRenderer, &gGhostVulnerableSpriteClips[ghostVulnerableFrame / (GHOST_VULNERABLE_SPRITES * 2)], 0.0);
                                } else {
                                    gInky.render(&gInky, &gInkyTexture, gRenderer, &gInkySpriteClips[gInky.mDirection][ghostFrame / (GHOSTS_WALKING_SPRITES * 4)], 0.0);
                                }
                            } else {
                                gInky.render(&gInky, &gInkyTexture, gRenderer, &gInkySpriteClips[gInky.mDirection + GHOST_DEAD_EFFECT][0], 0.0);
                            }
                            
                            // Renderiza o fantasma laranja
                            if(!gClyde.mDead){
                                if(gotPowerUp){
                                    gClyde.render(&gClyde, &gClydeTexture, gRenderer, &gGhostVulnerableSpriteClips[ghostVulnerableFrame / (GHOST_VULNERABLE_SPRITES * 2)], 0.0);
                                } else {
                                    gClyde.render(&gClyde, &gClydeTexture, gRenderer, &gClydeSpriteClips[gClyde.mDirection][ghostFrame / (GHOSTS_WALKING_SPRITES * 4)], 0.0);
                                }
                            } else {
                                gClyde.render(&gClyde, &gClydeTexture, gRenderer, &gClydeSpriteClips[gClyde.mDirection + GHOST_DEAD_EFFECT][0], 0.0);
                            }
                            
                            if(pacmanDead){
                                gPacman.mVelX = 0;
                                gPacman.mVelY = 0;
                                // Renderiza o pacman
                                gPacman.render(&gPacman, &gPacmanTexture, gRenderer, &gPacmanDiesSpriteClips[pacmanDeadFrame / PACMAN_DEATH_SPRITES], 0.0);
                            }else {
                                
                                // Captura a posição do blinky antes de movê-lo
                                int blinkyLastX = gBlinky.mBox.x;
                                int blinkyLastY = gBlinky.mBox.y;
                                
                                // Captura a posição do pinky antes de movê-lo
                                int pinkyLastX = gPinky.mBox.x;
                                int pinkyLastY = gPinky.mBox.y;
                                
                                // Captura a posição do inky antes de movê-lo
                                int inkyLastX = gInky.mBox.x;
                                int inkyLastY = gInky.mBox.y;
                                
                                // Captura a posição do clyde antes de movê-lo
                                int clydeLastX = gClyde.mBox.x;
                                int clydeLastY = gClyde.mBox.y;
                                
                                gBlinky.move(&gBlinky, tileSet);
                                gPinky.move(&gPinky, tileSet);
                                gInky.move(&gInky, tileSet);
                                gClyde.move(&gClyde, tileSet);
                                
                                // Define o frame que o blinky será renderizado de acordo com o movimento que ele fez 
                                if(blinkyLastX < gBlinky.mBox.x) gBlinky.mDirection = GHOST_RIGHT;
                                else if(blinkyLastX > gBlinky.mBox.x) gBlinky.mDirection = GHOST_LEFT;
                                else if(blinkyLastY < gBlinky.mBox.y) gBlinky.mDirection = GHOST_DOWN;
                                else if(blinkyLastY > gBlinky.mBox.y) gBlinky.mDirection = GHOST_UP;
                                
                                // Define o frame que o pinky será renderizado de acordo com o movimento que ele fez 
                                if(pinkyLastX < gPinky.mBox.x) gPinky.mDirection = GHOST_RIGHT;
                                else if(pinkyLastX > gPinky.mBox.x) gPinky.mDirection = GHOST_LEFT;
                                else if(pinkyLastY < gPinky.mBox.y) gPinky.mDirection = GHOST_DOWN;
                                else if(pinkyLastY > gPinky.mBox.y) gPinky.mDirection = GHOST_UP;
                                
                                // Define o frame que o inky será renderizado de acordo com o movimento que ele fez 
                                if(inkyLastX < gInky.mBox.x) gInky.mDirection = GHOST_RIGHT;
                                else if(inkyLastX > gInky.mBox.x) gInky.mDirection = GHOST_LEFT;
                                else if(inkyLastY < gInky.mBox.y) gInky.mDirection = GHOST_DOWN;
                                else if(inkyLastY > gInky.mBox.y) gInky.mDirection = GHOST_UP;
                                
                                // Define o frame que o clyde será renderizado de acordo com o movimento que ele fez 
                                if(clydeLastX < gClyde.mBox.x) gClyde.mDirection = GHOST_RIGHT;
                                else if(clydeLastX > gClyde.mBox.x) gClyde.mDirection = GHOST_LEFT;
                                else if(clydeLastY < gClyde.mBox.y) gClyde.mDirection = GHOST_DOWN;
                                else if(clydeLastY > gClyde.mBox.y) gClyde.mDirection = GHOST_UP;
                                
                                // Renderiza o pacman
                                gPacman.render(&gPacman, &gPacmanTexture, gRenderer, &gPacmanSpriteClips[pacmanFrame / PACMAN_WALKING_SPRITES], (double) gPacman.mDirection);
                                
                            }
                            
                        /* Não ta servindo pra nada isso aqui ainda, pretendo usar pra salvar as melhores pontuações
                        |   // for(int i = 0; i < TOTAL_DATA; i++){
                        |   //     gDataTexture[i].render(&gDataTexture[i], (SCREEN_WIDTH - gDataTexture[i].mWidth) / 2, gScoreTextTexture.mHeight + gDataTexture[0].mHeight * i, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                        |   // }
                        |   
                        */
                        
                        }
                    }   
                

               
                
                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* TELA INICIAL DO JOGO:
|       TEXTO COM UM FADE COM O LINK DO REPOSITÓRIO OPEN SOURCE NO GITHUB
|       TELA DE ABERTURA DO JOGO, ESPERANDO QUE O ENTER SEJA PRESSIONADO PARA COMEÇAR O JOGO
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                if(!gameStarted) {
                    if(!Mix_Playing(CHANNEL_TWO)) Mix_PlayChannel(CHANNEL_TWO, gIntermissionMusic, CONTINUOUS_LOOP);
                    gPacmanLogoTexture.render(&gPacmanLogoTexture, (SCREEN_WIDTH - gPacmanLogoTexture.mWidth) / 2, SCREEN_HEIGHT / 4, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    gPressEnterTextTexture.render(&gPressEnterTextTexture, (SCREEN_WIDTH - gPressEnterTextTexture.mWidth) / 2, 3 * SCREEN_HEIGHT / 4 , gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    gDevTextTexture.setAlpha(&gDevTextTexture, devTextAlpha);
                    if(devTextAlpha > 0) SDL_RenderClear(gRenderer);
                    gDevTextTexture.render(&gDevTextTexture, (SCREEN_WIDTH - gDevTextTexture.mWidth) / 2, SCREEN_HEIGHT / 2 , gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    if(devTextAlpha > 0) SDL_Delay(10);
                    if(devTextAlpha > 0) devTextAlpha--;
                    if(devTextAlpha < 0) devTextAlpha = 0;
                }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           
           
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* RENDERIZA TUDO QUE FOI FEITO NA TELA */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                
                // Atualiza a tela
                SDL_RenderPresent(gRenderer);

                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* LIMITE A QUANTIDADE DE FRAMES PER SECOND PRA PRÓXIMO DE 60 FPS, DEIXANDO O JOGO JOGÁVEL DE FATO, SEM FICAR ACELERADO DEMAIS */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                
                // Calcula e corrige o FPS
                float avgFPS = countedFrames / (fpsTimer.getTicks(&fpsTimer) / SECONDSCOUNTER);
                if(avgFPS > MAX_AVGFPS){
                    avgFPS = 0;
                }
                
                countedFrames++;
                
                // Se o frame terminar cedo
                int frameTicks = capTimer.getTicks(&capTimer);
                if(frameTicks < SCREEN_TICKS_PER_FRAME){
                    // Espera o tempo restante
                    SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
                }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* INCREMENTA E REINICIA SE NECESSÁRIO OS FRAMES DAS SEGUINTES ANIMAÇÕES
|       PACMAN
|       FANTASMAS
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                // Vai para o próximo frame do Pacman
                pacmanFrame++;
                
                // Circula a animação do Pacman
                if(pacmanFrame / PACMAN_WALKING_SPRITES >= PACMAN_WALKING_SPRITES) pacmanFrame = 0;

                // Vai para o próximo frame dos fantasmas andando
                ghostFrame++;
                ghostVulnerableFrame++;
                
                // Circula a animação
                if(ghostFrame / (GHOSTS_WALKING_SPRITES * 4) >= GHOSTS_WALKING_SPRITES) ghostFrame = 0;
                if(ghostVulnerableFrame / (GHOST_VULNERABLE_SPRITES * 2) >= GHOST_VULNERABLE_SPRITES) ghostVulnerableFrame = 0;
                
                if(pacmanDead) pacmanDeadFrame++;
                if(pacmanDeadFrame / PACMAN_DEATH_SPRITES >= PACMAN_DEATH_SPRITES) {
                    pacmanDeadFrame = 0;
                    pacmanDead = false;
                    
                    // Coloca o pacman e os fantasmas na posição inicial;
                    gPacman.mBox.x = 32;
                    gPacman.mBox.y = 384;
                    gBlinky.mBox.x = 9 * 32;
                    gBlinky.mBox.y = 384;
                    gPinky.mBox.x = 10 * 32;
                    gPinky.mBox.y = 384;
                    gInky.mBox.x = 11 * 32;
                    gInky.mBox.y = 384;
                    gClyde.mBox.x = 12 * 32;
                    gClyde.mBox.y = 384;
                }
                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                
           /* Não ta servindo pra nada isso aqui ainda, pretendo usar pra salvar as melhores pontuações
            |    // Desabilita o input de texto
            |    // SDL_StopTextInput();
            |    // if(inputText) free(inputText);
            |
            */
                
                
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* QUANDO COMER TODAS AS PILLS: 
|       PASSAR DE NÍVEL, 
|       REMONTAR O MAPA, 
|       REPOSICIONAR O PACMAN E OS FANTASMAS, 
|       AUMENTAR A VELOCIDADE DO FANTASMA A CADA 2 NÍVEIS 
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                
                
                if(!pillsLeft){
                    
                    // Para todas as músicas
                    Mix_HaltChannel(ANY_CHANNEL);
                    
                    // Toca a música de passagem de nível
                    Mix_PlayChannel(ANY_CHANNEL, gIntermissionMusic, ONE_TIME);
                    
                    // Aumenta o contador de níveis
                    gLevel++;
                    
                    // Renderiza o novo nível na tela
                    // Limpa o renderizador
                    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
                    SDL_RenderClear(gRenderer);
                    memset(newLvlbuffer, '\0', sizeof(char) * 15);
                    sprintf(newLvlbuffer, "Nivel %d", gLevel);
                    gNewLevelTextTexture.loadFromRenderedText(&gNewLevelTextTexture, newLvlbuffer, textColor, gRenderer, gFont);
                    gNewLevelTextTexture.render(&gNewLevelTextTexture, (SCREEN_WIDTH - gNewLevelTextTexture.mWidth) / 2, SCREEN_HEIGHT / 2, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    SDL_RenderPresent(gRenderer);
                    
                    // Realoca todos as pills e powerups comidos
                    for(int i = 0; i < TOTAL_TILES; i++){
                        if(tileSet[i]->mRestore == TILE_PILL){
                            tileSet[i]->mRestore = TILE_PATH;
                            tileSet[i]->mType = TILE_PILL;
                        }
                        
                        if(tileSet[i]->mRestore == TILE_POWERUP){
                            tileSet[i]->mRestore = TILE_PATH;
                            tileSet[i]->mType = TILE_POWERUP;
                        }
                    }
                    
                    // Coloca o pacman e os fantasmas na posição inicial;
                    gPacman.mBox.x = 32;
                    gPacman.mBox.y = 384;
                    gBlinky.mBox.x = 9 * 32;
                    gBlinky.mBox.y = 384;
                    gPinky.mBox.x = 10 * 32;
                    gPinky.mBox.y = 384;
                    gInky.mBox.x = 11 * 32;
                    gInky.mBox.y = 384;
                    gClyde.mBox.x = 12 * 32;
                    gClyde.mBox.y = 384;
                    
                    // Reinicia a contagem de pillsLeft
                    pillsLeft = gTotalPills;
                    
                    // Aguarda 4 segundos antes de começar o próximo nível
                    SDL_Delay(NEWLVLPRESENTATION);                    
                }
                
                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                if(!lives && !pacmanDead){
                    // Limpa o renderizador
                    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
                    SDL_RenderClear(gRenderer);
                    gGameOverTextTexture.render(&gGameOverTextTexture, (SCREEN_WIDTH - gGameOverTextTexture.mWidth) / 2, SCREEN_HEIGHT / 2, gRenderer, NULL, 0.0, NULL, SDL_FLIP_NONE);
                    // Atualiza a tela
                    SDL_RenderPresent(gRenderer);
                    
                    SDL_Delay(7000);
                    quit = true;
                }

            }
        }
    }
    
    // Libera os recursos e fecha o SDL
    closeProgram(tileSet);
        
    return 0;
}