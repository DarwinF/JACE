#ifndef __JACE_Texture2D_H_
#define __JACE_Texture2D_H_

#include "../JACE_Common.h"
#include "../JACE_Graphics.h"
#include "../GraphicsEngine/Rectangle.h"

class Texture2D {
public:
    Texture2D(char *fileLocation);
    ~Texture2D();
    
    void Load();
    
    void Render(int x, int y);
    void Render(int x, int y, int w, int h);
    void Render(Rectangle ScreenDestination);
    void Render(Rectangle TextureSource, Rectangle ScreenDestination);
    void Render(Rectangle TextureSource, Rectangle ScreenDestination, int AnimationFrame, int AnimationFramesCount);
    void Render(Rectangle TextureSource, Rectangle ScreenDestination, int AnimationFrameX, int AnimationFramesCountX, int AnimationFrameY, int AnimationFramesCountY);
private:
    const int FILE_EXTENSION_LEN = 4;
    
    char *fileLocation;
    
    GLuint textureID;
    GLuint textureWidth;
    GLuint textureHeight;
    GLuint *pixels;
    
    void GetPNGData();
};

#endif
