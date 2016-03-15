#include "buttonObject.h"

void Button_object_setPosition(void *self, int x, int y)
{
    Button_object *button = self;
    
    button->mPosition.x = x;
    button->mPosition.y = y;
}


void Button_object_handleEvent(void *self, SDL_Event *e)
{
    Button_object *button = self;
    
    // Se um evento de mouse ocorrer
    if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
        // Pega a posição do mouse
        int x, y;
        SDL_GetMouseState(&x, &y);
        
        // Verifica se o mouse está num botão
        bool inside = true;
        
        // Mouse está à esquerda do botão
        if(x < button->mPosition.x){
            inside = false;
        }
        
        // Mouse está à direita do botão
        else if(x > button->mPosition.x + BUTTON_WIDTH){
            inside = false;
        }
        
        // Mouse está acima do botão
        else if(y < button->mPosition.y){
            inside = false;
        }
        
        // Mouse está abaixo do botão
        else if(y > button->mPosition.y + BUTTON_HEIGHT){
            inside = false;
        }
        
        // Mouse está fora do botão
        if(!inside){
            button->mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        } else {
            // Seta o mouse sobre o sprite
            switch(e->type){
                case SDL_MOUSEMOTION:
                    button->mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    break;
                    
                case SDL_MOUSEBUTTONDOWN:
                    button->mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                    break;
                    
                case SDL_MOUSEBUTTONUP:
                    button->mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                    break;
            }
        }      
    }
}

void Button_object_render(void *self, Texture_object *texture, SDL_Renderer *gRenderer, SDL_Rect *gSpriteClips)
{
    Button_object *button = self;
    
    // Exibe o botão do sprite
    texture->render(texture, button->mPosition.x, button->mPosition.y, gRenderer, &(gSpriteClips[button->mCurrentSprite]), 0.0, NULL, SDL_FLIP_NONE);
}


void Button_object_new(Button_object *button)
{
    if(!button->setPosition) button->setPosition = Button_object_setPosition;
    if(!button->handleEvent) button->handleEvent = Button_object_handleEvent;
    if(!button->render) button->render = Button_object_render;
    
    button->mPosition.x = 0;
    button->mPosition.y = 0;
    
    button->mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}