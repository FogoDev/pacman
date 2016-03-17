#ifndef _globals_h
#define _globals_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "textureObject.h"
#include "buttonObject.h"
#include "timeObject.h"
#include "constantsNdefines.h"
#include "dotObject.h"

// A Janela em que vamos renderizar os bangs
extern SDL_Window *gWindow;

// O renderizador da janela
extern SDL_Renderer *gRenderer;

// Fonte usada globalmente
extern TTF_Font *gFont;

// Fonte usada na tela inicial
extern TTF_Font *gDevFont;

// Objetos de textura
//extern SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
//extern Button_object gButtons[TOTAL_BUTTONS];


extern Texture_object gPacmanTexture;
extern SDL_Rect gPacmanSpriteClips[PACMAN_WALKING_SPRITES];
extern int pacmanFrame;


extern Texture_object gScoreTextTexture;
extern Texture_object gPointsTextTexture;
extern Texture_object gLivesTextTexture;

// extern Texture_object gDataTexture[TOTAL_DATA];
extern Texture_object gTileTexture;

extern SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

// Variável pra guardar a pontuação do jogador
extern unsigned long long int gScore;


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

// Temporizador
extern Time_object fpsTimer;
extern Time_object capTimer;

// O ponto que vamos mexer pela tela
extern Dot_object gPacman;

// Data points
extern Sint32 gData[TOTAL_DATA];

// Mapa de tiles
extern Tile_object *tileSet[TOTAL_TILES];

// Textura do texto do desenvolvedor
extern Texture_object gDevTextTexture;

// Texturas da Tela inicial
extern Texture_object gPacmanLogoTexture;
extern Texture_object gPressEnterTextTexture;

// Quantidade total de pills e powerups no mapa
extern int gTotalPills;

// Nível do jogo, começando do 1;
extern int gLevel;

// Textura de novo nível
extern Texture_object gNewLevelTextTexture;


#endif