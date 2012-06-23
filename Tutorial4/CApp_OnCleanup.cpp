#include "CApp.h"

void CApp::OnCleanup(){
	// Free surfaces
	SDL_FreeSurface(surf_grid);
	SDL_FreeSurface(surf_x);
	SDL_FreeSurface(surf_o);
	SDL_FreeSurface(surf_display);
	SDL_FreeSurface(surf_winning);
	SDL_FreeSurface(surf_title);
	SDL_FreeSurface(surf_draw);

	// Free sounds
	Mix_FreeChunk(drip1);
	Mix_FreeChunk(drip2);
	Mix_CloseAudio();

	SDL_Quit();
}
