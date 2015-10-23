#ifndef __JACE_CONTENT_HANDLER_H_
#define __JACE_CONTENT_HANDLER_H_

#include "../JACE_Graphics.h"
#include "../JACE_Common.h"

#include "Texture2D.h"

class ContentHandler {
public:
    ContentHandler();
    ~ContentHandler();
    
    template <class Texture2D>
    Texture2D *LoadContent(char *fileLoc) {
        Texture2D *img = new Texture2D(fileLoc);
        img->Load();
        return img;
    };
private:
};

#endif
