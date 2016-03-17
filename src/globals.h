#ifndef _globals_h
#define _globals_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "textureObject.h"
#include "timeObject.h"
#include "constantsNdefines.h"
#include "dotObject.h"


//////////////////////////// SDL STUFF /////////////////////////

// A Janela em que vamos renderizar os bangs
extern SDL_Window *gWindow;

// O renderizador da janela
extern SDL_Renderer *gRenderer;

////////////////////////////////////////////////////////////////

//////////////////////////// PACMAN //////////////////////////// 

// Textura do pacman
extern Texture_object gPacmanTexture;

// Clips dos sprites do pacman
extern SDL_Rect gPacmanSpriteClips[PACMAN_WALKING_SPRITES];

// Ponto do pacman
extern Dot_object gPacman;

////////////////////////////////////////////////////////////////

//////////////////////////// FANTASMAS /////////////////////////

// Fantasma vermelho
extern Texture_object gBlinkyTexture;
extern SDL_Rect gBlinkySpriteClips[GHOST_DIRECTION_TOTAL][GHOSTS_WALKING_SPRITES];
extern Dot_object gBlinky;

// Fantasma rosa
extern Texture_object gPinkyTexture;
extern SDL_Rect gPinkySpriteClips[GHOST_DIRECTION_TOTAL][GHOSTS_WALKING_SPRITES];
extern Dot_object gPinky;

// Fantasma azul
extern Texture_object gInkyTexture;
extern SDL_Rect gInkySpriteClips[GHOST_DIRECTION_TOTAL][GHOSTS_WALKING_SPRITES];
extern Dot_object gInky;

// Fantasma laranja
extern Texture_object gClydeTexture;
extern SDL_Rect gClydeSpriteClips[GHOST_DIRECTION_TOTAL][GHOSTS_WALKING_SPRITES];
extern Dot_object gClyde;

// Sprite clips pros fantasmas quando vulneráveis
extern SDL_Rect gGhostVulnerableSpriteClips[GHOST_VULNERABLE_SPRITES];

////////////////////////////////////////////////////////////////

//////////////////////////// MAPA //////////////////////////////

// Tiles do mapa
extern Texture_object gTileTexture;

// Clips de tiles do mapa
extern SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

// Mapa de tiles
extern Tile_object *tileSet[TOTAL_TILES];

////////////////////////////////////////////////////////////////

//////////////////////////// TEXTOS ////////////////////////////

// Fonte usada globalmente
extern TTF_Font *gFont;

// Fonte usada na tela inicial igual a gFont, porém com um tamanho menor
extern TTF_Font *gDevFont;

// Textura do texto do desenvolvedor
extern Texture_object gDevTextTexture;

// Texturas da Tela inicial
extern Texture_object gPressEnterTextTexture;
extern Texture_object gPacmanLogoTexture;

// Textos usados na tela de jogo
extern Texture_object gScoreTextTexture;
extern Texture_object gPointsTextTexture;
extern Texture_object gLivesTextTexture;

// Textura de novo nível
extern Texture_object gNewLevelTextTexture;


// Texture_object gDataTexture[TOTAL_DATA];
// Sint32 gData[TOTAL_DATA];

////////////////////////////////////////////////////////////////

//////////////////////////// SONS //////////////////////////////

// As músicas que serão tocadas
extern Mix_Chunk *gSirenMusic;
extern Mix_Chunk *gIntermissionMusic;

// Os efeitos sonoros que serão usados
extern Mix_Chunk *gDiesSoundEffect;
extern Mix_Chunk *gEatingCherrySoundEffect;
extern Mix_Chunk *gEatingGhostSoundEffect;
extern Mix_Chunk *gExtraLiveSoundEffect;
extern Mix_Chunk *gOpeningSoundEffect;
extern Mix_Chunk *gWakaWakaSoundEffect;

////////////////////////////////////////////////////////////////

//////////////////////////// EXTRAS ////////////////////////////

// Quantidade total de pills e powerups no mapa
extern int gTotalPills;

// Nível do jogo, começando do 1;
extern int gLevel;

// Variável pra guardar a pontuação do jogador
extern unsigned long long int gScore;

// Temporizador para contar o fps
extern Time_object fpsTimer;

// Temporizador pra limitar o fps
extern Time_object capTimer;

////////////////////////////////////////////////////////////////


#endif