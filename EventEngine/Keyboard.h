#ifndef __JACE_KEYBOARD_H_
#define __JACE_KEYBOARD_H_

#include "../JACE_Common.h"
#include <SDL.h>

/* List of Keyboard Keys */
enum Key {
	ZERO 	= SDL_SCANCODE_0,
	ONE 	= SDL_SCANCODE_1,
	TWO 	= SDL_SCANCODE_2,
	THREE 	= SDL_SCANCODE_3,
	FOUR 	= SDL_SCANCODE_4,
	FIVE 	= SDL_SCANCODE_5,
	SIX 	= SDL_SCANCODE_6,
	SEVEN 	= SDL_SCANCODE_7,
	EIGHT 	= SDL_SCANCODE_8,
	NINE 	= SDL_SCANCODE_9,

	APOSTROPHE 	= SDL_SCANCODE_APOSTROPHE,
	COMMA 		= SDL_SCANCODE_COMMA,
	TILDE		= SDL_SCANCODE_GRAVE,
	PERIOD		= SDL_SCANCODE_PERIOD,
	SEMICOLON	= SDL_SCANCODE_SEMICOLON,
	
	BACKSLASH 	= SDL_SCANCODE_BACKSLASH,
	BACKSPACE 	= SDL_SCANCODE_BACKSPACE,
	EQUALS 		= SDL_SCANCODE_EQUALS,
	ESCAPE 		= SDL_SCANCODE_ESCAPE,
	DASH		= SDL_SCANCODE_MINUS,
	RETURN		= SDL_SCANCODE_RETURN,
	SLASH 		= SDL_SCANCODE_SLASH,
	SPACE 		= SDL_SCANCODE_SPACE,
	TAB			= SDL_SCANCODE_TAB,

	DELETE 		= SDL_SCANCODE_DELETE,
	END 		= SDL_SCANCODE_END,
	HOME		= SDL_SCANCODE_HOME,
	INSERT 		= SDL_SCANCODE_INSERT,
	PAGE_UP 	= SDL_SCANCODE_PAGEUP,
	PADGE_DOWN	= SDL_SCANCODE_PAGEDOWN,

	LEFT_ALT		= SDL_SCANCODE_LALT,
	LEFT_CONTROL	= SDL_SCANCODE_LCTRL,
	LEFT_SHIFT		= SDL_SCANCODE_LSHIFT,
	LEFT_META		= SDL_SCANCODE_LGUI,
	RIGHT_ALT		= SDL_SCANCODE_RALT,
	RIGHT_CONTROL	= SDL_SCANCODE_RCTRL,
	RIGHT_SHIFT		= SDL_SCANCODE_RSHIFT,
	RIGHT_META		= SDL_SCANCODE_RGUI,

	A = SDL_SCANCODE_A,
	B = SDL_SCANCODE_B,	
	C = SDL_SCANCODE_C,
	D = SDL_SCANCODE_D,
	E = SDL_SCANCODE_E,
	F = SDL_SCANCODE_F,	
	G = SDL_SCANCODE_G,
	H = SDL_SCANCODE_H,
	I = SDL_SCANCODE_I,
	J = SDL_SCANCODE_J,
	K = SDL_SCANCODE_K,
	L = SDL_SCANCODE_L,
	M = SDL_SCANCODE_M,
	N = SDL_SCANCODE_N,
	O = SDL_SCANCODE_O,
	P = SDL_SCANCODE_P,
	Q = SDL_SCANCODE_Q,
	R = SDL_SCANCODE_R,
	S = SDL_SCANCODE_S,
	T = SDL_SCANCODE_T,
	U = SDL_SCANCODE_U,
	V = SDL_SCANCODE_V,
	W = SDL_SCANCODE_W,
	X = SDL_SCANCODE_X,
	Y = SDL_SCANCODE_Y,
	Z = SDL_SCANCODE_Z,

	DOWN_ARROW 	= SDL_SCANCODE_DOWN,
	LEFT_ARROW 	= SDL_SCANCODE_LEFT,
	RIGHT_ARROW = SDL_SCANCODE_RIGHT,
	UP_ARROW	= SDL_SCANCODE_UP,

	F1 	= SDL_SCANCODE_F1,
	F2 	= SDL_SCANCODE_F2,
	F3 	= SDL_SCANCODE_F3,
	F4 	= SDL_SCANCODE_F4,
	F5 	= SDL_SCANCODE_F5,
	F6 	= SDL_SCANCODE_F6,
	F7 	= SDL_SCANCODE_F7,
	F8 	= SDL_SCANCODE_F8,
	F9 	= SDL_SCANCODE_F9,
	F10	= SDL_SCANCODE_F10,
	F11 = SDL_SCANCODE_F11,
	F12 = SDL_SCANCODE_F12
};

#define PRESSED     0
#define RELEASED    1

class Keyboard {
public:
    Keyboard();
    ~Keyboard();
    
    jBoolean IsKeyDown(Key);
    jBoolean IsKeyUp(Key);
private:
    const Uint8 *keyState;
};

#endif