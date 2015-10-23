#include "Game.h"

int xPos, yPos;
int frameNumber;
int lastUpdate = 0;
Boolean pRunning = False;

Game::Game() {
	graphicsEngine = new GraphicsEngine();
    renderer = graphicsEngine->Initialize();

	running = True;

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
        running = False;
    }
    
    if (keyboard->IsKeyDown(A)) {
        xPos -= 5;
        pRunning = True;
        lastUpdate++;
    }
    else if (keyboard->IsKeyDown(D)) {
        pRunning = True;
        xPos += 5;
        lastUpdate++;
    }
    else {
        pRunning = False;
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
