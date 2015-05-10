#include "EventSystem.h"
#include <SDL.h>

EventSystem::EventSystem() {
    
}

EventSystem::~EventSystem() {
    
}

jBoolean EventSystem::PollQuit() {
    jBoolean quit = FALSE;
    
    SDL_Event sevent;
    SDL_PollEvent(&sevent);
    
    if (sevent.type == SDL_QUIT)
        quit = TRUE;
    
    return quit;
}