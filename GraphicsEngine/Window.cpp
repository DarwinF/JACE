#include "Window.h"

// Constructor
Window::Window() {
    mainWindow = NULL;
    windowTitle[0] = '\0';
    
	// int status = SetWindowToDesktop();
	// 0 = success; <0 = failure

	SetWindowTitle(DEFAULT_TITLE);

	CreateWindow();
}

// Destructor
Window::~Window() {
	SDL_DestroyWindow(mainWindow);
}

// Sets the windowTitle variable to a string with
// a max length of MAX_TITLE_LEN
// Sets mainWindow Title to the variable if it has
// been initialized
void Window::SetWindowTitle(char *title) {
	int winLen = (int)strlen(windowTitle);
	int titleLen = (int)strlen(title);
	int totalLen = winLen + titleLen;

	if(totalLen == titleLen)
		strcpy(windowTitle, title);
	else if (totalLen < MAX_TITLE_LEN)
		strcat(windowTitle, title);
	else {
		int catLen = MAX_TITLE_LEN - winLen - 1;
		strncat(windowTitle, title, catLen);
	}

	if (mainWindow != NULL)
		SDL_SetWindowTitle(mainWindow, windowTitle);
}

// Creates a window to display content in
void Window::CreateWindow() {
#ifndef NDEBUG // We are debugging so we want a special window
    windowWidth = DEBUG_WIDTH;
    windowHeight = DEBUG_HEIGHT;
    
	SetWindowTitle(DEBUG_TITLE_APPEND); // with special title

	mainWindow = SDL_CreateWindow(	windowTitle, DEFAULT_POS_X,
                                    DEFAULT_POS_Y, DEBUG_WIDTH,
									DEBUG_HEIGHT, WINDOW_WINDOWED);
#else // We are not debugging so make a normal window
	mainWindow = SDL_CreateWindow(	windowTitle, DEFAULT_POS_X, 
					  				DEFAULT_POS_Y, windowWidth, 
					  				windowHeight, WINDOW_FULLSCREEN);
#endif
}

// Set window width and window height to the desktop width and height
int Window::SetWindowToDesktop() {
	SDL_DisplayMode *currDesktop = nullptr;
	int status;

	status = SDL_GetCurrentDisplayMode(DEFAULT_DISPLAY_INDEX, currDesktop);

	windowWidth = currDesktop->w;
	windowHeight = currDesktop->h;

	return status;
}
