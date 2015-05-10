#ifndef __JACE_MOUSE_H_
#define __JACE_MOUSE_H_

#include <SDL.h>
#include "../JACE_Common.h"

#define LEFT_BUTTON     1
#define MIDDLE_BUTTON   2
#define RIGHT_BUTTON    3

class Mouse {
public:
    Mouse();
    ~Mouse();
    
    // Getters
    jBoolean GetVisibility() { return isVisible; };
    jBoolean GetMouseButtonPressed(int button);
    int GetMouseXLocation();
    int GetMouseYLocation();
    
    // Setters
    void SetVisibility(jBoolean visible) { isVisible = visible; };
private:
    jBoolean isVisible;
};

#endif