#include "Game.h"
#include <stdio.h>

#ifdef __linux__
	#include <GL/freeglut.h>
	#include <GL/gl.h>
#elif __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <OpenGL/gl.h>
#endif

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

int xPos, yPos;
int frameNumber;
int lastUpdate = 0;
_Bool pRunning = FALSE;

Game::Game() {
	graphicsEngine = new GraphicsEngine();
    renderer = graphicsEngine->Initialize();

	running = TRUE;

	// Initialize Game Code Here
    keyboard = new Keyboard();
    eventSystem = new EventSystem();
    
    xPos = 50;
    yPos = 400;
    frameNumber = 0;
}

Game::~Game() {
	// Put Unloading Code Here
}
	
void Game::LoadContent() {
    
}
	
void Game::Update() {
	// Put Update Code Here
    if (keyboard->IsKeyDown(ESCAPE) || eventSystem->PollQuit()) {
        running = FALSE;
    }
    
    if (keyboard->IsKeyDown(A)) {
        xPos -= 5;
        pRunning = TRUE;
        lastUpdate++;
    }
    else if (keyboard->IsKeyDown(D)) {
        pRunning = TRUE;
        xPos += 5;
        lastUpdate++;
    }
    else {
        pRunning = FALSE;
        frameNumber = 0;
        lastUpdate = 0;
    }
    
    if (pRunning) {
        if (lastUpdate == 5) {
            frameNumber++;
            lastUpdate = 0;
        }
        
        if (frameNumber == 8)
            frameNumber = 0;
    }
}

void Game::Draw() {
	// Put Drawing Code Here
    float DEFAULT_COLOR[4] = { 0.0f, 0.4f, 0.7f, 1.0f };
    renderer->Clear(DEFAULT_COLOR);

    renderer->DrawRectangle(xPos, yPos, 50, 40);
    
    renderer->Finish();
}
