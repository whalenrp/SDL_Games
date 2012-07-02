#include "Blackjack.h"

void Blackjack::onRender(){
	CSurface::OnDraw(surf_screen, surf_background, 0, 0);
	player1.onDraw(surf_screen, play_1_x, play_1_y);
	dealer.onDraw(surf_screen, dealer_x, dealer_y);
	SDL_Flip(surf_screen);
}

