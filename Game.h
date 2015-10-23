#ifndef __JACE_GAME_H_
#define __JACE_GAME_H_

#include "JACE_Common.h"

#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Renderer.h"
#include "EventEngine/Keyboard.h"
#include "EventEngine/EventSystem.h"

class Game {
public:
	Game();
	~Game();

	void LoadContent();
	void Update();
	void Draw();

	Boolean IsRunning() { return running; };
private:
	GraphicsEngine *graphicsEngine;
    Renderer *renderer;

    Keyboard *keyboard;
    EventSystem *eventSystem;
    
	Boolean running;
};

#endif