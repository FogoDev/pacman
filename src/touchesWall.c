#include "touchesWall.h"


// Checa a colisão contra os tijolos do mapa
bool touchesWall(SDL_Rect box, Tile_object *tiles[], bool ghost)
{
    // Percorre os tiles
    for(int i = 0; i < TOTAL_TILES; i++){
        
        // Se o tile for do tipo parede;
        if((tiles[i]->mType > TILE_POWERUP) && tiles[i]->mType < TILE_CAGE_DOOR){
            
            // Se o circulo de colisão do ponto tocar uma parede de tile
            if(checkSSCollision(box, tiles[i]->mBox)){
                return true;
            }
        } else if((tiles[i]->mType == TILE_CAGE_DOOR)){
            if(!ghost){
                if(checkSSCollision(box, tiles[i]->mBox)){
                    return true;
                }
            }
        }
    }
    
    // Se nenhuma parede foi tocada
    return false;
}