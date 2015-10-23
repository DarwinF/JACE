#include "Game.h"

int main(int argc, char **argv) {
	Game *game = new Game();
    
	game->LoadContent();
    
	do {
		game->Update();
		game->Draw();
	}while(game->IsRunning());
    
	return 0;
}
