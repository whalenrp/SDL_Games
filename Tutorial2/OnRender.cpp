#include "CApp.h"

void CApp::OnRender(){
	CSurface::OnDraw(surf_display, surf_test, 0, 0);
	CSurface::OnDraw(surf_display, surf_test, 200, 200, 0, 0, 50, 50);

	SDL_Flip(surf_display);
}
