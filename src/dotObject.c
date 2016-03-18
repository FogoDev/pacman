#include "dotObject.h"


void Dot_object_handleEvent(void *self, SDL_Event *e)
{
    Dot_object *dot = self;
    
    // Se uma tecla for pressionada
    if(e->type == SDL_KEYDOWN && e->key.repeat == 0){
        
        // Ajusta a velocidade
        switch(e->key.keysym.sym){
            case SDLK_UP:
                dot->mVelY -= dot->DOT_VEL;
                break;
                
            case SDLK_DOWN:
                dot->mVelY += dot->DOT_VEL;
                break;
                
            case SDLK_LEFT:
                dot->mVelX -= dot->DOT_VEL;
                break;
                
            case SDLK_RIGHT:
                dot->mVelX += dot->DOT_VEL;
                break;
        }
    }
    
    // Se a tecla for solta
    else if(e->type == SDL_KEYUP && e->key.repeat == 0){
        
        // Ajusta a velocidade
        switch(e->key.keysym.sym){
            case SDLK_UP:
                dot->mVelY += dot->DOT_VEL;
                break;
                
            case SDLK_DOWN:
                dot->mVelY -= dot->DOT_VEL;
                break;
                
            case SDLK_LEFT:
                dot->mVelX += dot->DOT_VEL;
                break;
                
            case SDLK_RIGHT:
                dot->mVelX -= dot->DOT_VEL;
                break;
        }
    }
}


void Dot_object_move(Dot_object *dot, Tile_object *tiles[])
{
    
    //Move the dot left or right
    dot->mBox.x += dot->mVelX;

    //If the dot went too far to the left or right or touched a wall
    if(touchesWall( dot->mBox, tiles, dot->mGhost)){
        //move back
        dot->mBox.x -= dot->mVelX;
    } else if(dot->mBox.x < 0){
        dot->mBox.x = SCREEN_WIDTH - dot->mBox.w;
    } else if(dot->mBox.x + dot->DOT_WIDTH > SCREEN_WIDTH){
        dot->mBox.x = 0;
    }

    //Move the dot up or down
    dot->mBox.y += dot->mVelY;

    //If the dot went too far up or down or touched a wall
    if( ( dot->mBox.y < 0 ) || ( dot->mBox.y + dot->DOT_HEIGHT > SCREEN_HEIGHT ) || touchesWall( dot->mBox, tiles, dot->mGhost ) )
    {
        //move back
        dot->mBox.y -= dot->mVelY;
    }
    
    
    
    // //Move o ponto pra direita ou pra esquerda;
    // dot->mBox.x += dot->mVelX;
    // dot->shiftColliders(dot);
    
    // // Se o ponto for longe de mais pra direita ou pra esquerda
    // if(touchesWall(dot->mCollider, tiles, dot->mGhost)){
    //     // Move de volta
    //     dot->mBox.x -= dot->mVelX;
    //     dot->shiftColliders(dot);
    // } else if((dot->mBox.x - dot->mCollider.r < 0)){
    //     dot->mBox.x = SCREEN_WIDTH - dot->mCollider.r;
    //     dot->shiftColliders(dot);
    // } else if((dot->mBox.x + dot->mCollider.r > SCREEN_WIDTH)){
    //     dot->mBox.x = 0 + dot->mCollider.r;
    //     dot->shiftColliders(dot);
    // }
    
    // //Move o ponto pra cima ou pra baixo;
    // dot->mBox.y += dot->mVelY;
    // dot->shiftColliders(dot);
    
    // // Se o ponto for longe de mais pra cima ou pra baixo
    // if((dot->mBox.y - dot->mCollider.r < 0) || ((dot->mBox.y + dot->mCollider.r) > SCREEN_HEIGHT) || touchesWall(dot->mCollider, tiles, dot->mGhost)){
    //     // Move de volta
    //     dot->mBox.y -= dot->mVelY;
    //     dot->shiftColliders(dot);
    // }  
}


void Dot_object_render(void *self, Texture_object *texture, SDL_Renderer *gRenderer, SDL_Rect *gSpriteClip, double angle)
{
    Dot_object *dot = self;
    
    // Renderiza o ponto na tela
    texture->render(texture, (dot->mBox.x), (dot->mBox.y), gRenderer, gSpriteClip, angle, NULL, SDL_FLIP_NONE);
}


void Dot_object_new(Dot_object *dot, int x, int y, bool ghost)
{
    
    // Aloca os métodos do objeto
    if(!dot->handleEvent) dot->handleEvent = Dot_object_handleEvent;
    if(ghost){
        if(!dot->move) dot->move = Dot_object_moveGhost;
    } else {
        if(!dot->move) dot->move = Dot_object_move;
    }
    if(!dot->render) dot->render = Dot_object_render;
    
    
    // Inicia as constantes do ponto
    *(int *)&dot->DOT_WIDTH = 32;
    *(int *)&dot->DOT_HEIGHT = 32;
    dot->DOT_VEL = 2;
    
    // Inicia o raio de colisão do ponto
    //dot->mCollider.r = dot->DOT_WIDTH / 2;
    
    // A direção que o ponto está andando
    dot->mDirection = 0;
    
    // Inicia os atributos do ponto
    // dot->mBox.x = x + dot->DOT_WIDTH;
    // dot->mBox.y = y + dot->DOT_HEIGHT;
    dot->mVelX = 0;
    dot->mVelY = 0;
    
    dot->mBox.x = x;
    dot->mBox.y = y;
    dot->mBox.w = dot->DOT_WIDTH;
    dot->mBox.h = dot->DOT_HEIGHT;
    
    // Atributos exclusivos de fantasmas
    dot->mGhost = ghost;
    dot->mXInversor = false;
    dot->mYInversor = false;
    dot->mDead = false;
    
    
}


void Dot_object_moveGhost(Dot_object *ghost, Tile_object *tiles[])
{
    
    int random;
    // random = rand();
    // random %= 2;
    
    // if(random){
        if(ghost->mXInversor){
            ghost->mBox.x -= ghost->DOT_VEL;
        } else {
            ghost->mBox.x += ghost->DOT_VEL;
        }
    // }
    

    if((ghost->mBox.x - ghost->DOT_WIDTH < 0) || ((ghost->mBox.x + ghost->DOT_WIDTH) > SCREEN_WIDTH) || touchesWall(ghost->mBox, tiles, ghost->mGhost)){
        
        if(ghost->mXInversor){
            ghost->mBox.x += ghost->DOT_VEL;
        } else {
            ghost->mBox.x -= ghost->DOT_VEL;
        }
        random = rand();
        random %= 5;
        if(!random) ghost->mXInversor = !ghost->mXInversor;
    }
   
    // random = rand();
    // random %= 2;
    
    // if(random){
        if(ghost->mYInversor){
            ghost->mBox.y -= ghost->DOT_VEL;
        } else {
            ghost->mBox.y += ghost->DOT_VEL;
        }
    // }
    
    
    if((ghost->mBox.y - ghost->DOT_HEIGHT < 0) || ((ghost->mBox.y + ghost->DOT_HEIGHT) > SCREEN_HEIGHT) || touchesWall(ghost->mBox, tiles, ghost->mGhost)){
        if(ghost->mYInversor){
            ghost->mBox.y += ghost->DOT_VEL;
        } else {
            ghost->mBox.y -= ghost->DOT_VEL;
        }
        random = rand();
        random %= 5;
       
        if(!random) ghost->mYInversor = !ghost->mYInversor;
    }
    
   
    
}