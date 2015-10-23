#include "EventSystem.h"

EventSystem::EventSystem() {
    
}

EventSystem::~EventSystem() {
    
}

Boolean EventSystem::PollQuit() {
    Boolean quit = False;
    
    SDL_Event sevent;
    SDL_PollEvent(&sevent);
    
    if (sevent.type == SDL_QUIT)
        quit = True;
    
    return quit;
}