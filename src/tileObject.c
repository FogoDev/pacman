#include "tileObject.h"


void Tile_object_render(void *self, Texture_object *texture, SDL_Renderer *gRenderer, SDL_Rect *gTileClips)
{
    Tile_object *tile = self;
    
    // Renderiza o tile
    texture->render(texture, tile->mBox.x, tile->mBox.y, gRenderer, &(gTileClips[tile->mType]), 0.0, NULL, SDL_FLIP_NONE);
}


Tile_object* Tile_object_new(Tile_object *tile, int x, int y, int tileType)
{
    tile = (Tile_object *) malloc (sizeof(Tile_object));
      
    if(!tile->render) tile->render = Tile_object_render;
    
    // Atribui as posições
    tile->mBox.x = x;
    tile->mBox.y = y;
    
    // Inicializa a collision box
    tile->mBox.w = TILE_WIDTH;
    tile->mBox.h = TILE_HEIGHT;
    
    // Atribui o tipo de tile
    tile->mType = tileType;
    if(tile->mType == 1 || tile->mType == 2) tile->mRestore = 0;
    else tile->mRestore = 5;
    
    return tile;
}


// Inicializa os tijolos no mapa
int setTiles(Tile_object *tiles[], SDL_Rect *gTileClips)
{
    // Flag de sucesso
    int tilesLoaded = 0;
    
    // As posições dos tiles
    int x = 0, y = 0;
    
    // Abre o mapa
    FILE *map = fopen("../res/maps/map1.map", "r");
    if(!map){
        printf("Falha ao carregar mapa!\n");
        tilesLoaded = false;
    } else {
        // Inicializa os tiles
        for(int i = 0; i < TOTAL_TILES; i++){
            
            // Determina qual tipo de tile será feito
            int tileType = -1;
            
            // Lê um tile do mapa
            fscanf(map, "%d", &tileType);
            
            if(ferror(map)){
                // Para o carregamento do mapa
                printf("Erro ao carregar mapa: Fim inesperado do arquivo!\n");
                tilesLoaded = false;
                break;
            }
                        
            // Verifica se o número é válido
            if((tileType >= 0) && (tileType < TOTAL_TILE_SPRITES)){
                if(tileType == 1 || tileType == 2) tilesLoaded++;
                tiles[i] = Tile_object_new(tiles[i], x, y, tileType);
            }
            
            // Se não reconhecermos um dos tipos
            else {
                // Parar o carregamento do mapa
                printf("Erro ao carregar mapa: Tipo de tile invalido em %d!\n", i);
                tilesLoaded = false;
                break;
            }
            
            // Move para a posição do próximo tile
            x += TILE_WIDTH;
            
            // Se a tela acabar
            if(x >= SCREEN_WIDTH){
                // Reinicia o x
                x = 0;
                
                // Move pra linha de baixo
                y += TILE_HEIGHT;                
            }
            
        }
        
        if(tilesLoaded){
            gTileClips[TILE_PATH].x = 64;
            gTileClips[TILE_PATH].y = 32;
            gTileClips[TILE_PATH].w = TILE_WIDTH;
            gTileClips[TILE_PATH].h = TILE_HEIGHT;
            
            gTileClips[TILE_PILL].x = 64;
            gTileClips[TILE_PILL].y = 64;
            gTileClips[TILE_PILL].w = TILE_WIDTH;
            gTileClips[TILE_PILL].h = TILE_HEIGHT;
            
            gTileClips[TILE_POWERUP].x = 96;
            gTileClips[TILE_POWERUP].y = 64;
            gTileClips[TILE_POWERUP].w = TILE_WIDTH;
            gTileClips[TILE_POWERUP].h = TILE_HEIGHT;
            
            gTileClips[TILE_HORIZONTAL].x = 0;
            gTileClips[TILE_HORIZONTAL].y = 0;
            gTileClips[TILE_HORIZONTAL].w = TILE_WIDTH;
            gTileClips[TILE_HORIZONTAL].h = TILE_HEIGHT;

            gTileClips[TILE_VERTICAL].x = 32;
            gTileClips[TILE_VERTICAL].y = 0;
            gTileClips[TILE_VERTICAL].w = TILE_WIDTH;
            gTileClips[TILE_VERTICAL].h = TILE_HEIGHT;

            gTileClips[TILE_END_RIGHT].x = 64;
            gTileClips[TILE_END_RIGHT].y = 0;
            gTileClips[TILE_END_RIGHT].w = TILE_WIDTH;
            gTileClips[TILE_END_RIGHT].h = TILE_HEIGHT;
            
            gTileClips[TILE_END_TOP].x = 96;
            gTileClips[TILE_END_TOP].y = 0;
            gTileClips[TILE_END_TOP].w = TILE_WIDTH;
            gTileClips[TILE_END_TOP].h = TILE_HEIGHT;
            
            gTileClips[TILE_END_BOTTOM].x = 128;
            gTileClips[TILE_END_BOTTOM].y = 0;
            gTileClips[TILE_END_BOTTOM].w = TILE_WIDTH;
            gTileClips[TILE_END_BOTTOM].h = TILE_HEIGHT;
            
            gTileClips[TILE_END_LEFT].x = 160;
            gTileClips[TILE_END_LEFT].y = 0;
            gTileClips[TILE_END_LEFT].w = TILE_WIDTH;
            gTileClips[TILE_END_LEFT].h = TILE_HEIGHT;

            gTileClips[TILE_CURVE_TOP_RIGHT].x = 0;
            gTileClips[TILE_CURVE_TOP_RIGHT].y = 32;
            gTileClips[TILE_CURVE_TOP_RIGHT].w = TILE_WIDTH;
            gTileClips[TILE_CURVE_TOP_RIGHT].h = TILE_HEIGHT;
            
            gTileClips[TILE_CURVE_RIGHT_BOTTOM].x = 32;
            gTileClips[TILE_CURVE_RIGHT_BOTTOM].y = 32;
            gTileClips[TILE_CURVE_RIGHT_BOTTOM].w = TILE_WIDTH;
            gTileClips[TILE_CURVE_RIGHT_BOTTOM].h = TILE_HEIGHT;

            gTileClips[TILE_CURVE_TOP_LEFT].x = 32;
            gTileClips[TILE_CURVE_TOP_LEFT].y = 64;
            gTileClips[TILE_CURVE_TOP_LEFT].w = TILE_WIDTH;
            gTileClips[TILE_CURVE_TOP_LEFT].h = TILE_HEIGHT;

            gTileClips[TILE_CURVE_LEFT_TOP].x = 0;
            gTileClips[TILE_CURVE_LEFT_TOP].y = 64;
            gTileClips[TILE_CURVE_LEFT_TOP].w = TILE_WIDTH;
            gTileClips[TILE_CURVE_LEFT_TOP].h = TILE_HEIGHT;

            gTileClips[TILE_T_TOP].x = 0;
            gTileClips[TILE_T_TOP].y = 96;
            gTileClips[TILE_T_TOP].w = TILE_WIDTH;
            gTileClips[TILE_T_TOP].h = TILE_HEIGHT;

            gTileClips[TILE_T_BOTTOM].x = 32;
            gTileClips[TILE_T_BOTTOM].y = 96;
            gTileClips[TILE_T_BOTTOM].w = TILE_WIDTH;
            gTileClips[TILE_T_BOTTOM].h = TILE_HEIGHT;

            gTileClips[TILE_T_LEFT].x = 32;
            gTileClips[TILE_T_LEFT].y = 128;
            gTileClips[TILE_T_LEFT].w = TILE_WIDTH;
            gTileClips[TILE_T_LEFT].h = TILE_HEIGHT;

            gTileClips[TILE_T_RIGHT].x = 0;
            gTileClips[TILE_T_RIGHT].y = 128;
            gTileClips[TILE_T_RIGHT].w = TILE_WIDTH;
            gTileClips[TILE_T_RIGHT].h = TILE_HEIGHT;

            gTileClips[TILE_CAGE_TOP_LEFT].x = 64;
            gTileClips[TILE_CAGE_TOP_LEFT].y = 96;
            gTileClips[TILE_CAGE_TOP_LEFT].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_TOP_LEFT].h = TILE_HEIGHT;

            gTileClips[TILE_CAGE_TOP_RIGHT].x = 128;
            gTileClips[TILE_CAGE_TOP_RIGHT].y = 96;
            gTileClips[TILE_CAGE_TOP_RIGHT].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_TOP_RIGHT].h = TILE_HEIGHT;

            gTileClips[TILE_CAGE_HORIZONTAL_RIGHT].x = 128;
            gTileClips[TILE_CAGE_HORIZONTAL_RIGHT].y = 128;
            gTileClips[TILE_CAGE_HORIZONTAL_RIGHT].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_HORIZONTAL_RIGHT].h = TILE_HEIGHT;
            
            gTileClips[TILE_CAGE_TOP].x = 96;
            gTileClips[TILE_CAGE_TOP].y = 128;
            gTileClips[TILE_CAGE_TOP].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_TOP].h = TILE_HEIGHT;
            
            gTileClips[TILE_CAGE_BOTTOM_RIGHT].x = 128;
            gTileClips[TILE_CAGE_BOTTOM_RIGHT].y = 160;
            gTileClips[TILE_CAGE_BOTTOM_RIGHT].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_BOTTOM_RIGHT].h = TILE_HEIGHT;
            
            gTileClips[TILE_CAGE_BOTTOM].x = 96;
            gTileClips[TILE_CAGE_BOTTOM].y = 160;
            gTileClips[TILE_CAGE_BOTTOM].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_BOTTOM].h = TILE_HEIGHT;
            
            gTileClips[TILE_CAGE_BOTTOM_LEFT].x = 64;
            gTileClips[TILE_CAGE_BOTTOM_LEFT].y = 160;
            gTileClips[TILE_CAGE_BOTTOM_LEFT].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_BOTTOM_LEFT].h = TILE_HEIGHT;
            
            gTileClips[TILE_CAGE_HORIZONTAL_LEFT].x = 64;
            gTileClips[TILE_CAGE_HORIZONTAL_LEFT].y = 128;
            gTileClips[TILE_CAGE_HORIZONTAL_LEFT].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_HORIZONTAL_LEFT].h = TILE_HEIGHT;
            
            gTileClips[TILE_CAGE_DOOR].x = 96;
            gTileClips[TILE_CAGE_DOOR].y = 96;
            gTileClips[TILE_CAGE_DOOR].w = TILE_WIDTH;
            gTileClips[TILE_CAGE_DOOR].h = TILE_HEIGHT;
            
        }
    }
    
    // Fecha o arquivo
    fclose(map);
    
    // Retorna se o mapa foi carregado ou não
    return tilesLoaded;
}