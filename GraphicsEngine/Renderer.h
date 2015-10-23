#ifndef __JACE_RENDERER_H_
#define __JACE_RENDERER_H_

#include "../JACE_Common.h"
#include "../JACE_Graphics.h"
#include "Window.h"

class Window;
const static int COLOR_SIZE = 4;

class Renderer {
public:
    Renderer(Window *);
    ~Renderer();
    
    void Draw();
    void DrawRectangle(int, int, int, int);
    void Clear(float color[COLOR_SIZE]);
    void Finish();
private:
    Window *window;
};

#endif