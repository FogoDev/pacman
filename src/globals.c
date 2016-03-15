#include "globals.h"

// A Janela em que vamos renderizar os bangs
SDL_Window *gWindow = NULL;

// O renderizador da janela
SDL_Renderer *gRenderer = NULL;

// Fonte usada globalmente
TTF_Font *gFont = NULL;

// Objetos de textura e de botões
//SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
//Button_object gButtons[TOTAL_BUTTONS];
// Texture_object gPressTexture;
// Texture_object gUpTexture;
// Texture_object gDownTexture;
// Texture_object gLeftTexture;
// Texture_object gRightTexture;
Texture_object gPacmanTexture;

Texture_object gScoreTextTexture;
Texture_object gPointsTextTexture;
Texture_object gLivesTextTexture;
// Texture_object gDataTexture[TOTAL_DATA];
Texture_object gTileTexture;

SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

// Variável pra guardar a pontuação do jogador
unsigned long long int gScore = 0;


// // A música que será tocada
// Mix_Music *gMusic = NULL;

// // Os efeitos sonoros que serão usados
// Mix_Chunk *gScratch = NULL;
// Mix_Chunk *gHigh = NULL;
// Mix_Chunk *gMedium = NULL;
// Mix_Chunk *gLow = NULL;

// Temporizador para contar o fps
Time_object fpsTimer;

// Temporizador pra limitar o fps
Time_object capTimer;

// O ponto que vamos mexer pela tela
Dot_object gPacman;

// Iniciando outro ponto
//Dot_object otherDot;

// Data points
Sint32 gData[TOTAL_DATA];

// Mapa de tiles
Tile_object *tileSet[TOTAL_TILES];