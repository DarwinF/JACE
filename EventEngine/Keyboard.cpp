#include "Keyboard.h"

Keyboard::Keyboard() {
    keyState = SDL_GetKeyboardState(NULL);
}

Keyboard::~Keyboard() {
    
}

jBoolean Keyboard::IsKeyDown(Key key) {
    jBoolean isDown = FALSE;

    SDL_PumpEvents();
    
    if (keyState[key])
        isDown = TRUE;
    
    return isDown;
}

jBoolean Keyboard::IsKeyUp(Key key) {
    jBoolean isUp = FALSE;

    SDL_PumpEvents();
    
    if (!keyState[key])
        isUp = TRUE;
    
    return isUp;
}