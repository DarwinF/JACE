#include "Renderer.h"

Renderer::Renderer(Window *win) {
    window = win;
}

Renderer::~Renderer() {
    
}

void Renderer::Draw() {
    
}

void Renderer::DrawRectangle(int x, int y, int w, int h) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef(x, y, 0.f);
    
    glBegin( GL_QUADS);
    glColor3f(0.f, 0.f, 1.f);
    glVertex2i(0, 0);
    glVertex2i(w, 0);
    glVertex2i(w, h);
    glVertex2i(0, h);
    glEnd();
    
    glColor3f(1.f, 1.f, 1.f);
}

void Renderer::Clear(float color[COLOR_SIZE]) {
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Finish() {
    SDL_GL_SwapWindow(window->ToSDL_Window());
}
