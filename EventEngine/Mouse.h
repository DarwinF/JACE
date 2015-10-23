#ifndef __JACE_MOUSE_H_
#define __JACE_MOUSE_H_

#include "../JACE_Common.h"
#include "../JACE_Graphics.h"

#define LEFT_BUTTON     1
#define MIDDLE_BUTTON   2
#define RIGHT_BUTTON    3

class Mouse {
public:
    Mouse();
    ~Mouse();
    
    // Getters
    Boolean GetVisibility() { return isVisible; };
    Boolean GetMouseButtonPressed(int button);
    int GetMouseXLocation();
    int GetMouseYLocation();
    
    // Setters
    void SetVisibility(Boolean visible) { isVisible = visible; };
private:
    Boolean isVisible;
};

#endif