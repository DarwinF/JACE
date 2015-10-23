#include "GraphicsEngine.h"

// Null constructor that sets our 
GraphicsEngine::GraphicsEngine() {
	window = NULL;
	openGLContext = NULL;
}

// Initialize function that returns the Renderer the user is going
// to use to draw everything
Renderer * GraphicsEngine::Initialize() {
	// Initilize SDL elements seperately
	SDL_Init(SDL_BYPASS);
	SDL_InitSubSystem(SDL_INIT_TIMER);
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	SDL_InitSubSystem(SDL_INIT_EVENTS);

	if (SDL_WasInit(SDL_BYPASS) != SDL_INIT_MASK) {
		// Check what hasn't been initialized
		CheckSubSystems(SDL_INIT_TIMER);
		CheckSubSystems(SDL_INIT_VIDEO);
		CheckSubSystems(SDL_INIT_EVENTS);
	}

	window = new Window();
	InitOpenGL();

	// Return the renderer
    Renderer *temp = new Renderer(window);
    return temp;
}

// Destructor
GraphicsEngine::~GraphicsEngine() {
    SDL_GL_DeleteContext(openGLContext);
    
	SDL_QuitSubSystem(SDL_INIT_TIMER);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_QuitSubSystem(SDL_INIT_EVENTS);

	SDL_Quit();
}

// Checks if the individual subsystem has been initialized
void GraphicsEngine::CheckSubSystems(int subSystem) {
	if (SDL_WasInit(subSystem) == 0) {
		// Log error
	}
}

void GraphicsEngine::InitOpenGL() {
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    openGLContext = SDL_GL_CreateContext(window->ToSDL_Window());
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, window->GetWindowWidth_d(), window->GetWindowHeight_d(), 0.0, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	GLenum error = glGetError();

	if (openGLContext == NULL) {
		fprintf(stderr, "Error\nSDL: %s\n", SDL_GetError());
	}

    glEnable(GL_TEXTURE_2D);
}
