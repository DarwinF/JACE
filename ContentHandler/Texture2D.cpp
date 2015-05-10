#include "Texture2D.h"

#include "Textures/PNGTex.h"

#ifdef __linux__
	#include <GL/freeglut.h>
#elif __APPLE__
	#include <OpenGL/gl.h>
#endif

Texture2D::Texture2D(string fileLoc) {
    fileLocation = fileLoc;
    
    textureID = 0;
    textureHeight = 0;
    textureWidth = 0;
}

Texture2D::~Texture2D() {
    
}

void Texture2D::Load() {
    if (fileLocation.compare(fileLocation.size() - FILE_EXTENSION_LEN, FILE_EXTENSION_LEN, ".png") == 0) {
        GetPNGData();
    }
    else {
        // ERROR
    }
}

void Texture2D::Render(int x, int y) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Sets the point x,y to 0,0
    glTranslatef(x, y, 0.f);
    
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_QUADS);
    
    GLdouble h1 = 0;
    GLdouble w1 = 0;
    GLdouble h2 = 1;
    GLdouble w2 = 1;
    
    glTexCoord2d(w1,h2);
    glVertex2i(0, 0);
    
    glTexCoord2d(w2,h2);
    glVertex2i(textureWidth, 0);
    
    glTexCoord2d(w2,h1);
    glVertex2i(textureWidth, textureHeight);
    
    glTexCoord2d(w1,h1);
    glVertex2i(0, textureHeight);
    
    glEnd();
    
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
}

void Texture2D::Render(int x, int y, int w, int h) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Sets the point x,y to 0,0
    glTranslatef(x, y, 0.f);
    
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_QUADS);
    
    GLdouble h1 = 0;
    GLdouble w1 = 0;
    GLdouble h2 = 1;
    GLdouble w2 = 1;
    
    glTexCoord2d(w1,h2);
    glVertex2i(0, 0);
    
    glTexCoord2d(w2,h2);
    glVertex2i(w, 0);
    
    glTexCoord2d(w2,h1);
    glVertex2i(w, h);
    
    glTexCoord2d(w1,h1);
    glVertex2i(0, h);
    
    glEnd();
    
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
}

void Texture2D::Render(Rectangle ScreenDestination) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Sets the point x,y to 0,0
    glTranslatef(ScreenDestination.GetX(), ScreenDestination.GetY(), 0.f);
    
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_QUADS);
    
    GLdouble h1 = 0;
    GLdouble w1 = 0;
    GLdouble h2 = 1;
    GLdouble w2 = 1;
    
    glTexCoord2d(w1,h2);
    glVertex2i(0, 0);
    
    glTexCoord2d(w2,h2);
    glVertex2i(ScreenDestination.GetWidth(), 0);
    
    glTexCoord2d(w2,h1);
    glVertex2i(ScreenDestination.GetWidth(), ScreenDestination.GetHeight());
    
    glTexCoord2d(w1,h1);
    glVertex2i(0, ScreenDestination.GetHeight());
    
    glEnd();
    
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
}

void Texture2D::Render(Rectangle TextureSource, Rectangle ScreenDestination) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Sets the point x,y to 0,0
    glTranslatef(ScreenDestination.GetX(), ScreenDestination.GetY(), 0.f);
    
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_QUADS);
    
    GLdouble frameWidth = GLdouble(TextureSource.GetWidth()) / GLdouble(textureWidth);
    GLdouble frameHeight = GLdouble(TextureSource.GetHeight()) / GLdouble(textureHeight);
    
    GLdouble h1 = 0;
    GLdouble w1 = 0;
    GLdouble h2 = frameHeight;
    GLdouble w2 = frameWidth;
    
    glTexCoord2d(w1,h2);
    glVertex2i(0, 0);
    
    glTexCoord2d(w2,h2);
    glVertex2i(ScreenDestination.GetWidth(), 0);
    
    glTexCoord2d(w2,h1);
    glVertex2i(ScreenDestination.GetWidth(), ScreenDestination.GetHeight());
    
    glTexCoord2d(w1,h1);
    glVertex2i(0, ScreenDestination.GetHeight());
    
    glEnd();
    
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
}

void Texture2D::Render(Rectangle TextureSource, Rectangle ScreenDestination, int AnimationFrame, int AnimationFramesCount) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Sets the point x,y to 0,0
    glTranslatef(ScreenDestination.GetX(), ScreenDestination.GetY(), 0.f);
    
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_QUADS);
    
    GLdouble frameWidth = GLdouble(TextureSource.GetWidth()) / GLdouble(textureWidth);
    
    GLdouble h1 = 0;
    GLdouble w1 = (AnimationFrame % AnimationFramesCount) * frameWidth;
    GLdouble h2 = 1;
    GLdouble w2 = w1 + frameWidth;
    
    glTexCoord2d(w1,h2);
    glVertex2i(0, 0);
    
    glTexCoord2d(w2,h2);
    glVertex2i(ScreenDestination.GetWidth(), 0);
    
    glTexCoord2d(w2,h1);
    glVertex2i(ScreenDestination.GetWidth(), ScreenDestination.GetHeight());
    
    glTexCoord2d(w1,h1);
    glVertex2i(0, ScreenDestination.GetHeight());
    
    glEnd();
    
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
}

void Texture2D::Render(Rectangle TextureSource, Rectangle ScreenDestination, int AnimationFrameX, int AnimationFramesCountX, int AnimationFrameY, int AnimationFramesCountY) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Sets the point x,y to 0,0
    glTranslatef(ScreenDestination.GetX(), ScreenDestination.GetY(), 0.f);
    
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_QUADS);
    
    GLdouble frameWidth = GLdouble(TextureSource.GetWidth()) / GLdouble(textureWidth);
    GLdouble frameHeight = GLdouble(TextureSource.GetHeight()) / GLdouble(textureHeight);
    
    GLdouble h1 = (AnimationFrameY % AnimationFramesCountY) * frameHeight;
    GLdouble w1 = (AnimationFrameX % AnimationFramesCountX) * frameWidth;
    GLdouble h2 = h1 + frameHeight;
    GLdouble w2 = w1 + frameWidth;
    
    glTexCoord2d(w1,h2);
    glVertex2i(0, 0);
    
    glTexCoord2d(w2,h2);
    glVertex2i(ScreenDestination.GetWidth(), 0);
    
    glTexCoord2d(w2,h1);
    glVertex2i(ScreenDestination.GetWidth(), ScreenDestination.GetHeight());
    
    glTexCoord2d(w1,h1);
    glVertex2i(0, ScreenDestination.GetHeight());
    
    glEnd();
    
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
}

void Texture2D::GetPNGData() {
    PNGTex *tex = new PNGTex(fileLocation);
    
    textureWidth = tex->getWidth();
    textureHeight = tex->getHeight();
    textureID = tex->getID();
    
    delete tex;
}
