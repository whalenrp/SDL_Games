#include "CApp.h"

void CApp::OnCleanup(){
	SDL_FreeSurface(surf_test);
	SDL_FreeSurface(surf_display);
	SDL_Quit();
}
