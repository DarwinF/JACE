#ifndef __JACE_CONTENT_HANDLER_H_
#define __JACE_CONTENT_HANDLER_H_

#ifdef __linux__
	#include <GL/freeglut.h>
#elif __APPLE__
	#include <OpenGL/OpenGL.h>
#endif

#include "Texture2D.h"
#include "../JACE_Common.h"

class ContentHandler {
public:
    ContentHandler();
    ~ContentHandler();
    
    template <class Texture2D>
    Texture2D *LoadContent(string fileLoc) {
        Texture2D *img = new Texture2D(fileLoc);
        img->Load();
        return img;
    };
private:
};

#endif
