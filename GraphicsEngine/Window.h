#ifndef __JACE_WINDOW_H_
#define __JACE_WINDOW_H_

// RenderEngine Include
#include "../JACE_Common.h"
#include "Rectangle.h"
#include <SDL.h>

// Constants
#define DEFAULT_POS_X			SDL_WINDOWPOS_CENTERED
#define DEFAULT_POS_Y			SDL_WINDOWPOS_CENTERED
#define DEFAULT_TITLE			"My Game"

#define DEBUG_WIDTH 			800
#define DEBUG_HEIGHT 			600
#define DEBUG_TITLE_APPEND		" -- Debug"

#define WINDOW_WINDOWED					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
#define WINDOW_FULLSCREEN_DEFAULT 		SDL_WINDOW_FULLSCREEN_DEKSTOP | SDL_WINDOW_OPENGL
#define WINDOW_FULLSCREEN				SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL	// Needs a specified resolution
#define WINDOW_BORDERLESS_FULLSCREEN 	(SDL_WINDOW_FULLSCREEN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL)

#define DEFAULT_DISPLAY_INDEX			0

#define MAX_TITLE_LEN					32


class Window
{
public:
	// Constructors
	Window();

	// Destructor
	~Window();

	// Setters
	void SetWindowTitle(char *);
	void SetWindowSize(int w, int h) { windowWidth = w; windowHeight = h; };
	void SetWindowHeight(int h) { windowHeight = h; };
	void SetWindowWidth(int w) { windowWidth = w; };

	SDL_Window *ToSDL_Window() { return mainWindow; };

	// Getters
	char * GetWindowTitle() { return windowTitle; };
	int GetWindowWidth_i() { return windowWidth; };
	int GetWindowHeight_i() { return windowHeight; };
    double GetWindowWidth_d() { return double(windowWidth); }
    double GetWindowHeight_d() { return double(windowHeight); }
private:
	// Functions
	void CreateWindow();
	int SetWindowToDesktop();

	// Data
	SDL_Window *mainWindow;

	// Window Data
	char windowTitle[MAX_TITLE_LEN - 1];
	int windowWidth;
	int windowHeight;
};

#endif
