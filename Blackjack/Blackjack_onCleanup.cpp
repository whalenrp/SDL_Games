#include "Blackjack.h"

void Blackjack::onCleanup(){
	SDL_FreeSurface(surf_screen);
	SDL_FreeSurface(surf_background);
	mDeck.onCleanup();
	player1.onCleanup();
	TTF_Quit();
}
