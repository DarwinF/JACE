#include "Mouse.h"

Mouse::Mouse() {
    isVisible = TRUE;
    
}
Mouse::~Mouse() {
    
}

jBoolean Mouse::GetMouseButtonPressed(int button) {
    jBoolean pressed = FALSE;
    
    if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(button))
        pressed = TRUE;
    
    return pressed;
}

int GetMouseXLocation() {
    int *x = NULL;
    
    SDL_GetMouseState(x, NULL);
    
    return x[0];
}

int GetMouseYLocation() {
    int *y = NULL;
    
    SDL_GetMouseState(NULL, y);
    
    return y[0];
}
