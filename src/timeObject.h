#ifndef _timeObject_h
#define _timeObject_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "constantsNdefines.h"


typedef struct _Time_object {
    
    // Várias ações do relógio
    void (*start)(void *self);
    void (*stop)(void *self);
    void (*pause)(void *self);
    void (*unpause)(void *self);
    
    // Pega o tempo do temporizador
    Uint32 (*getTicks)(void *self);
    
    // O tempo do relógio quando o temporizador começou
    Uint32 mStartTicks;
    
    // Os ticks guardados quando o temporizador foi pausado
    Uint32 mPausedTicks;
    
    // O status do temporizador
    bool mPaused;
    bool mStarted;
    
} Time_object;

void Time_object_start(void *self);
void Time_object_stop(void *self);
void Time_object_pause(void *self);
void Time_object_unpause(void *self);
Uint32 Time_object_getTicks(void *self);

void Time_object_new(Time_object *time);

#endif