#include "Blackjack.h"

bool Blackjack::onInit(){
	char background[] = "./gfx/background.png";
	if(TTF_Init() == -1)
		return false;

	// Load surfaces
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

	if ((surf_screen = SDL_SetVideoMode(
			800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))== 0)
		return false;
	if ((surf_background = CSurface::OnLoad(background))==0)
		return false;


	if(!mDeck.onInit())
		return false;
	mDeck.shuffle();
	if (!player1.onInit())
		return false;

	return true;
}

