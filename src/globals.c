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
Texture_object gPacmanTexture;
SDL_Rect gPacmanSpriteClips[PACMAN_WALKING_SPRITES];
int pacmanFrame = 0;

Texture_object gScoreTextTexture;
Texture_object gPointsTextTexture;
Texture_object gLivesTextTexture;
// Texture_object gDataTexture[TOTAL_DATA];
Texture_object gTileTexture;

SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

// Variável pra guardar a pontuação do jogador
unsigned long long int gScore = 0;


// As músicas que serão tocadas
Mix_Music *gSirenMusic;
Mix_Music *gIntermissionMusic;

// Os efeitos sonoros que serão usados
Mix_Chunk *gDiesSoundEffect;
Mix_Chunk *gEatingCherrySoundEffect;
Mix_Chunk *gEatingGhostSoundEffect;
Mix_Chunk *gExtraLiveSoundEffect;
Mix_Chunk *gOpeningSoundEffect;
Mix_Chunk *gWakaWakaSoundEffect;

// Temporizador para contar o fps
Time_object fpsTimer;

// Temporizador pra limitar o fps
Time_object capTimer;

// O ponto que vamos mexer pela tela
Dot_object gPacman;

// Data points
Sint32 gData[TOTAL_DATA];

// Mapa de tiles
Tile_object *tileSet[TOTAL_TILES];