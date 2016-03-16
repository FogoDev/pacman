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


void Dot_object_move(void *self, Tile_object *tiles[])
{
    Dot_object *dot = self;
    
    //Move o ponto pra direita ou pra esquerda;
    dot->mPosX += dot->mVelX;
    dot->shiftColliders(dot);
    
    // Se o ponto for longe de mais pra direita ou pra esquerda
    if(touchesWall(dot->mCollider, tiles, dot->mGhost)){
        // Move de volta
        dot->mPosX -= dot->mVelX;
        dot->shiftColliders(dot);
    } else if((dot->mPosX - dot->mCollider.r < 0)){
        dot->mPosX = SCREEN_WIDTH - dot->mCollider.r;
        dot->shiftColliders(dot);
    } else if((dot->mPosX + dot->mCollider.r > SCREEN_WIDTH)){
        dot->mPosX = 0 + dot->mCollider.r;
        dot->shiftColliders(dot);
    }
    
    //Move o ponto pra cima ou pra baixo;
    dot->mPosY += dot->mVelY;
    dot->shiftColliders(dot);
    
    // Se o ponto for longe de mais pra cima ou pra baixo
    if((dot->mPosY - dot->mCollider.r < 0) || ((dot->mPosY + dot->mCollider.r) > SCREEN_HEIGHT) || touchesWall(dot->mCollider, tiles, dot->mGhost)){
        // Move de volta
        dot->mPosY -= dot->mVelY;
        dot->shiftColliders(dot);
    }  
}


void Dot_object_render(void *self, Texture_object *texture, SDL_Renderer *gRenderer, SDL_Rect *gSpriteClip, double angle)
{
    Dot_object *dot = self;
    
    // Renderiza o ponto na tela
    texture->render(texture, (dot->mPosX - dot->mCollider.r), (dot->mPosY - dot->mCollider.r), gRenderer, gSpriteClip, angle, NULL, SDL_FLIP_NONE);
}


void Dot_object_shiftColliders(void *self)
{
    Dot_object *dot = self;
    
    // Alinha os colisores com o centro do ponto
    dot->mCollider.x = dot->mPosX;
    dot->mCollider.y = dot->mPosY;
}


void Dot_object_new(Dot_object *dot, int x, int y, bool ghost)
{
    
    // Aloca os métodos do objeto
    if(!dot->handleEvent) dot->handleEvent = Dot_object_handleEvent;
    if(!dot->move) dot->move = Dot_object_move;
    if(!dot->render) dot->render = Dot_object_render;
    if(!dot->shiftColliders) dot->shiftColliders = Dot_object_shiftColliders;
    
    
    // Inicia as constantes do ponto
    *(int *)&dot->DOT_WIDTH = 32;
    *(int *)&dot->DOT_HEIGHT = 32;
    dot->DOT_VEL = 2;
    
    // Inicia o raio de colisão do ponto
    dot->mCollider.r = dot->DOT_WIDTH / 2;
    
    dot->mDirection = 0;
    
    // Inicia os atributos do ponto
    dot->mPosX = x + dot->DOT_WIDTH;
    dot->mPosY = y + dot->DOT_HEIGHT;
    dot->mVelX = 0;
    dot->mVelY = 0;
    dot->mGhost = ghost;
    
    // Inicializa os colisores relativos à posição
    dot->shiftColliders(dot);
}