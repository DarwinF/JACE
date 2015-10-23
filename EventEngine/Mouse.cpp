#include "Mouse.h"

Mouse::Mouse() {
    isVisible = True;
    
}
Mouse::~Mouse() {
    
}

Boolean Mouse::GetMouseButtonPressed(int button) {
    Boolean pressed = False;
    
    if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(button))
        pressed = True;
    
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
