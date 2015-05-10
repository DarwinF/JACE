#ifndef __JACE_GAME_H_
#define __JACE_GAME_H_

#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Renderer.h"
#include "EventEngine/Keyboard.h"
#include "EventEngine/EventSystem.h"

#include "JACE_Common.h"

class Game
{
public:
	Game();
	~Game();

	void LoadContent();
	void Update();
	void Draw();

	_Bool isRunning() { return running; };
private:
	GraphicsEngine *graphicsEngine;
    Renderer *renderer;

    Keyboard *keyboard;
    EventSystem *eventSystem;
    
	_Bool running;
};

#endif