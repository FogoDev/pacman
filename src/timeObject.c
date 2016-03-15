#include "timeObject.h"

void Time_object_start(void *self)
{
    Time_object *time = self;
    
    // Inicia o temporizador
    time->mStarted = true;
    
    // Despausa o temporizador
    time->mPaused = false;
    
    // Pega a hora atual do relógio
    time->mStartTicks = SDL_GetTicks();
    time->mPausedTicks = 0;
}


void Time_object_stop(void *self)
{
    Time_object *time = self;
    
    // Para o temporizador
    time->mStarted = false;
    
    //Despausa o temporizador
    time->mPaused = false;
    
    // Limpa as variáveis de ticks
    time->mStartTicks = 0;
    time->mPausedTicks = 0;
}


void Time_object_pause(void *self)
{
    Time_object *time = self;
    
    // Se o temporizador estiver rodando e não foi pausado
    if(time->mStarted && !time->mPaused){
        // Pausa o temporizador
        time->mPaused = true;
        
        // Calcula os ticks pausados
        time->mPausedTicks = SDL_GetTicks() - time->mStartTicks;
        time->mStartTicks = 0;
    }
}


void Time_object_unpause(void *self)
{
    Time_object *time = self;
    
    // Se o temporizador estiver rodando e pausado
    if(time->mStarted && time->mPaused){
        // Despausa o temporizador
        time->mPaused = false;
        
        // Reseta os ticks iniciais
        time->mStartTicks = SDL_GetTicks() - time->mPausedTicks;
        
        // Reseta os ticks pausados
        time->mPausedTicks = 0;
    }
}


Uint32 Time_object_getTicks(void *self)
{
    Time_object *time = self;
    
    // O tempo real do temporizador
    Uint32 tempo = 0;
    
    // Se o temporizador estiver rodando
    if(time->mStarted){
        // Se o temporizador estiver pausado
        if(time->mPaused){
            // Retorna o número de ticks de quando o temporizador foi pausado
            tempo = time->mPausedTicks;
        } else {
            // Retorna o tempo atual menos o tempo inicial
            tempo = SDL_GetTicks() - time->mStartTicks;
        }
    }
    
    return tempo;
}


void Time_object_new(Time_object *time)
{
    if(!time->start) time->start = Time_object_start;
    if(!time->stop) time->stop = Time_object_stop;
    if(!time->pause) time->pause = Time_object_pause;
    if(!time->unpause) time->unpause = Time_object_unpause;
    if(!time->getTicks) time->getTicks = Time_object_getTicks;

    time->mStartTicks = 0;
    time->mPausedTicks = 0;
    
    time->mPaused = false;
    time->mStarted = false;

}