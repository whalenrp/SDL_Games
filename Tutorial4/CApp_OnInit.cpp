#include "CApp.h"

bool CApp::OnInit(){
	char img_grid[] = "./gfx/grid.bmp";
	char img_o[] = "./gfx/o.bmp";
	char img_x[] = "./gfx/x.bmp";
	char img_winning[] = "./gfx/winning.bmp";
	char img_title[] = "./gfx/title.bmp";
	char img_draw[] = "./gfx/draw.bmp";
	char mix_drip1[] =  "./audio/drip1.wav";
	char mix_drip2[] = "./audio/drip2.wav";
		
	
	// Load surfaces	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

	if ((surf_display = SDL_SetVideoMode(
			600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))== 0)
		return false;
	
	if((surf_grid = CSurface::OnLoad(img_grid))==0)
		return false;

	if((surf_o = CSurface::OnLoad(img_o))==0)
		return false;

	if((surf_x = CSurface::OnLoad(img_x))==0)
		return false;

	if((surf_winning = CSurface::OnLoad(img_winning))==0)
		return false;

	if((surf_title = CSurface::OnLoad(img_title))==0)
		return false;

	if((surf_draw = CSurface::OnLoad(img_draw))==0)
		return false;

	CSurface::Transparent(surf_x, 255, 0, 255);
	CSurface::Transparent(surf_o, 255, 0, 255);
	CSurface::Transparent(surf_winning, 255, 0, 255);
	CSurface::Transparent(surf_title, 255, 0, 255);
	CSurface::Transparent(surf_draw, 255, 0, 255);

	// Load audio files
	if ( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return false;

	if ( (drip1 = Mix_LoadWAV(mix_drip1)) == 0)
		return false;
	if ( (drip2 = Mix_LoadWAV(mix_drip2)) == 0)
		return false;

	Reset();

	return true;
}


