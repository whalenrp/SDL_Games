#include "Blackjack.h"

void Blackjack::onRender(){
	CSurface::OnDraw(surf_screen, surf_background, 0, 0);
	player1.onDraw(surf_screen, 100, 100);
}
