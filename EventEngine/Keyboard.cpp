#include "Keyboard.h"

Keyboard::Keyboard() {
    keyState = SDL_GetKeyboardState(NULL);
}

Keyboard::~Keyboard() {
    
}

Boolean Keyboard::IsKeyDown(Key key) {
    Boolean isDown = False;

    SDL_PumpEvents();
    
    if (keyState[key])
        isDown = False;
    
    return isDown;
}

Boolean Keyboard::IsKeyUp(Key key) {
    Boolean isUp = False;

    SDL_PumpEvents();
    
    if (!keyState[key])
        isUp = True;
    
    return isUp;
}