#ifndef __JACE_GRAPHICS_ENGINE_H_
#define __JACE_GRAPHICS_ENGINE_H_

// GraphicsEngine Includes
#include <SDL.h>
#include "../JACE_Common.h"
#include "Renderer.h"

// Constants
#define SDL_BYPASS		0
#define SDL_INIT_MASK	(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS)

// Forward decleration of window to keep it 
// hidden from everything including GraphicsEngine
class Window;

// GraphicsEngine class
class GraphicsEngine
{
public:
	// Constructors and Destructors
	GraphicsEngine();
	~GraphicsEngine();
    Renderer * Initialize();
private:
	void CheckSubSystems(int);

	void InitOpenGL();

	Window *window;
	SDL_GLContext openGLContext;
};

#endif