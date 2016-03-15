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

// Objetos de textura
//extern SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
//extern Button_object gButtons[TOTAL_BUTTONS];


extern Texture_object gPacmanTexture;

extern Texture_object gScoreTextTexture;
extern Texture_object gPointsTextTexture;
extern Texture_object gLivesTextTexture;

// extern Texture_object gDataTexture[TOTAL_DATA];
extern Texture_object gTileTexture;

extern SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

// Variável pra guardar a pontuação do jogador
extern unsigned long long int gScore;


// // A música que será tocada
// extern Mix_Music *gMusic;

// // Os efeitos sonoros que serão usados
// extern Mix_Chunk *gScratch;
// extern Mix_Chunk *gHigh;
// extern Mix_Chunk *gMedium;
// extern Mix_Chunk *gLow;

// Temporizador
extern Time_object fpsTimer;
extern Time_object capTimer;

// O ponto que vamos mexer pela tela
extern Dot_object gPacman;

// // Iniciando outro ponto
// extern Dot_object otherDot;

// Data points
extern Sint32 gData[TOTAL_DATA];

// Mapa de tiles
extern Tile_object *tileSet[TOTAL_TILES];

#endif