#include "globals.h"


//////////////////////////// SDL STUFF /////////////////////////

// A Janela em que vamos renderizar os bangs
SDL_Window *gWindow = NULL;

// O renderizador da janela
SDL_Renderer *gRenderer = NULL;

////////////////////////////////////////////////////////////////

//////////////////////////// PACMAN //////////////////////////// 

// Textura do pacman
Texture_object gPacmanTexture;

// Clips dos sprites do pacman
SDL_Rect gPacmanSpriteClips[PACMAN_WALKING_SPRITES];

// Ponto do pacman
Dot_object gPacman;

////////////////////////////////////////////////////////////////

//////////////////////////// FANTASMAS /////////////////////////

// Fantasma vermelho
Texture_object gBlinkyTexture;
SDL_Rect gBlinkySpriteClips[GHOST_DIRECTION_TOTAL][GHOSTS_WALKING_SPRITES];
Dot_object gBlinky;

// Fantasma rosa
Texture_object gPinkyTexture;
SDL_Rect gPinkySpriteClips[GHOST_DIRECTION_TOTAL][GHOSTS_WALKING_SPRITES];
Dot_object gPinky;

// Fantasma azul
Texture_object gInkyTexture;
SDL_Rect gInkySpriteClips[GHOST_DIRECTION_TOTAL][GHOSTS_WALKING_SPRITES];
Dot_object gInky;

// Fantasma laranja
Texture_object gClydeTexture;
SDL_Rect gClydeSpriteClips[GHOST_DIRECTION_TOTAL][GHOSTS_WALKING_SPRITES];
Dot_object gClyde;

////////////////////////////////////////////////////////////////

//////////////////////////// MAPA //////////////////////////////

// Tiles do mapa
Texture_object gTileTexture;

// Clips de tiles do mapa
SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

// Mapa de tiles
Tile_object *tileSet[TOTAL_TILES];

////////////////////////////////////////////////////////////////

//////////////////////////// TEXTOS ////////////////////////////

// Fonte usada globalmente
TTF_Font *gFont = NULL;

// Fonte usada na tela inicial igual a gFont, porém com um tamanho menor
TTF_Font *gDevFont = NULL;

// Textura do texto do desenvolvedor
Texture_object gDevTextTexture;

// Texturas da Tela inicial
Texture_object gPressEnterTextTexture;
Texture_object gPacmanLogoTexture;

// Textos usados na tela de jogo
Texture_object gScoreTextTexture;
Texture_object gPointsTextTexture;
Texture_object gLivesTextTexture;

// Textura de novo nível
Texture_object gNewLevelTextTexture;


// Texture_object gDataTexture[TOTAL_DATA];
// Sint32 gData[TOTAL_DATA];

////////////////////////////////////////////////////////////////

//////////////////////////// SONS //////////////////////////////

// As músicas que serão tocadas
Mix_Chunk *gSirenMusic;
Mix_Chunk *gIntermissionMusic;

// Os efeitos sonoros que serão usados
Mix_Chunk *gDiesSoundEffect;
Mix_Chunk *gEatingCherrySoundEffect;
Mix_Chunk *gEatingGhostSoundEffect;
Mix_Chunk *gExtraLiveSoundEffect;
Mix_Chunk *gOpeningSoundEffect;
Mix_Chunk *gWakaWakaSoundEffect;

////////////////////////////////////////////////////////////////

//////////////////////////// EXTRAS ////////////////////////////

// Quantidade total de pills e powerups no mapa
int gTotalPills;

// Nível do jogo, começando do 1;
int gLevel = 1;

// Variável pra guardar a pontuação do jogador
unsigned long long int gScore = 0;

// Temporizador para contar o fps
Time_object fpsTimer;

// Temporizador pra limitar o fps
Time_object capTimer;

////////////////////////////////////////////////////////////////

