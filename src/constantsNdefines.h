#ifndef _constantsNdefines_h
#define _constantsNdefines_h

// Definindo constantes de tela
#define SCREEN_WIDTH 672
#define SCREEN_HEIGHT 800
#define SCREEN_FPS 60
#define SCREEN_TICKS_PER_FRAME 1000 / SCREEN_FPS


typedef short int bool;

#define false 0
#define true !false

typedef struct _Circle{
    int x, y;
    int r;
} Circle;

// Dados do arquivo de pontuação
#define TOTAL_DATA 10

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

// Constantes dos sprites dos fantasmas
#define GHOSTS_WALKING_SPRITES 2

enum _GHOST_DIRECTION
{
    GHOST_DOWN,
    GHOST_TOP,
    GHOST_LEFT,
    GHOST_RIGHT
};


#endif