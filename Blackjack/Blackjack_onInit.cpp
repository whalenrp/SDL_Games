#include "Blackjack.h"
#include <iostream>

bool Blackjack::onInit(){
	char background[] = "./gfx/background.png";
	if(TTF_Init() == -1)
		return false;

	// Load surfaces
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

	if ((surf_screen = SDL_SetVideoMode(
			1024, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))== 0)
		return false;

	// Initialize SDL_image library
	int flags = IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted&flags) != flags){
		std::cerr << "IMG_Init: failed to init image flags" << std::endl;
	}
	if ((surf_background = CSurface::OnLoad(background))==0)
		return false;


	if(!mDeck.onInit())
		return false;
	mDeck.shuffle();
	if (!player1.onInit())
		return false;
	if (!dealer.onInit())
		return false;

	Reset();

	return true;
}

