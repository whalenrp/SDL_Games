#include "CApp.h"

bool CApp::OnInit(){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

	if ((surf_display = SDL_SetVideoMode(
			640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))== 0)
		return false;

	if((surf_test = CSurface::OnLoad("myimage.bmp"))==0)
		return false;

	return true;
}


