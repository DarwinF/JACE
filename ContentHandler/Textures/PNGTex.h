#ifndef __JACE_PNG_TEX_H_
#define __JACE_PNG_TEX_H_

#include "../../JACE_Common.h"

#include <stdio.h>
#ifdef __linux__
	#include <GL/freeglut.h>
	#include <GL/gl.h>
#elif __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <OpenGl/gl.h>
#endif

class PNGTex {
public:
    PNGTex(string);
    ~PNGTex();
    
    GLuint getID() { return ID; }
    GLuint getWidth() { return width; }
    GLuint getHeight() { return height; }
private:
    FILE *image;
    string fileLocation;
    
    GLuint ID;
    GLuint width;
    GLuint height;
    
    GLuint LoadImage();
};

#endif
