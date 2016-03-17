#ifndef _constantsNdefines_h
#define _constantsNdefines_h

// Definindo constantes de tela
#define SCREEN_WIDTH 672
#define SCREEN_HEIGHT 800
#define SCREEN_FPS 60
#define SCREEN_TICKS_PER_FRAME 1000 / SCREEN_FPS
#define SECONDSCOUNTER 1000.0
#define MAX_AVGFPS 2000000

typedef short int bool;

#define false 0
#define true !false

typedef struct _Circle{
    int x, y;
    int r;
} Circle;

// Dados do arquivo de pontuação
#define TOTAL_DATA 10

// Vidas iniciais do pacman
#define STARTER_LIVES 3

// Define o tempo que a tela de troca de nível vai ficar na dela
#define NEWLVLPRESENTATION 4000

// Constante pra definir a pontuação pra conseguir vida extra
#define EXTRA_LIVE_SCORE 5000

// Quantidade de pontos dados ao comer pill e powerups
#define PILLSCORE 10
#define POWERUPSCORE 100

// Constantes do mapa
#define TILE_WIDTH 32
#define TILE_HEIGHT 32
#define TOTAL_TILES 525
#define TOTAL_TILE_SPRITES 26

// Os diferentes tipos de tijolos
enum _Tiles
{ 
    TILE_PATH,                  // 0
    TILE_PILL,                  // 1
    TILE_POWERUP,               // 2
    TILE_HORIZONTAL,            // 3
    TILE_VERTICAL,              // 4
    TILE_END_RIGHT,             // 5
    TILE_END_TOP,               // 6
    TILE_END_BOTTOM,            // 7
    TILE_END_LEFT,              // 8 
    TILE_CURVE_TOP_RIGHT,       // 9
    TILE_CURVE_RIGHT_BOTTOM,    // 10
    TILE_CURVE_TOP_LEFT,        // 11
    TILE_CURVE_LEFT_TOP,        // 12
    TILE_T_TOP,                 // 13
    TILE_T_BOTTOM,              // 14
    TILE_T_LEFT,                // 15
    TILE_T_RIGHT,               // 16
    TILE_CAGE_TOP_LEFT,         // 17
    TILE_CAGE_TOP_RIGHT,        // 18
    TILE_CAGE_HORIZONTAL_RIGHT, // 19
    TILE_CAGE_TOP,              // 20
    TILE_CAGE_BOTTOM_RIGHT,     // 21
    TILE_CAGE_BOTTOM,           // 22
    TILE_CAGE_BOTTOM_LEFT,      // 23
    TILE_CAGE_HORIZONTAL_LEFT,  // 24
    TILE_CAGE_DOOR              // 25
};


// Constantes de sprites do Pacman
#define PACMAN_WALKING_SPRITES 4
#define PACMAN_DEATH_SPRITES 12
enum _PACMAN_DIRECTION
{
    PACMAN_RIGHT = 0,
    PACMAN_LEFT = 180,
    PACMAN_DOWN = 90,
    PACMAN_UP = 270
};

// Constantes dos sprites dos fantasmas
#define GHOSTS_WALKING_SPRITES 2
#define GHOST_VULNERABLE_SPRITES 4
#define GHOST_DEAD_EFFECT 1
enum _GHOST_DIRECTION
{
    GHOST_DOWN,
    GHOST_DEAD_DOWN,
    GHOST_UP,
    GHOST_DEAD_UP,
    GHOST_LEFT,
    GHOST_DEAD_LEFT,
    GHOST_RIGHT,
    GHOST_DEAD_RIGHT,
    GHOST_VULNERABLE,
    GHOST_DIRECTION_TOTAL
};

// Constantes pra lidar com o SDL_MIX
enum _SOUND_CHANNELS
{
    ANY_CHANNEL = -1,
    CHANNEL_ZERO = 0,
    CHANNEL_ONE = 1,
    CHANNEL_TWO = 2,
    CHANNEL_THREE = 3,
    CHANNEL_FOUR = 4,
    CHANNEL_FIVE = 5,
    CHANNEL_SIX = 6,
    CHANNEL_SEVEN = 7
};

enum _SOUND_LOOP 
{
    CONTINUOUS_LOOP = -1,
    ONE_TIME = 0,
    LOOP_ONCE = 1,
    LOOP_TWICE = 2,
};

#endif