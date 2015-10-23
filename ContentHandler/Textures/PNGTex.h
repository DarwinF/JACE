#ifndef __JACE_PNG_TEX_H_
#define __JACE_PNG_TEX_H_

#include "../../JACE_Common.h"
#include "../../JACE_Graphics.h"

class PNGTex {
public:
	PNGTex(char *);
    ~PNGTex();
    
    GLuint getID() { return ID; }
    GLuint getWidth() { return width; }
    GLuint getHeight() { return height; }
private:
    FILE *image;
	char *fileLocation;
    
    GLuint ID;
    GLuint width;
    GLuint height;
    
    GLuint LoadImage();
};

#endif
