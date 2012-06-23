#include "CSurface.h"

CSurface::CSurface(){
}

SDL_Surface* CSurface::OnLoad(char* file){
	SDL_Surface* surf_temp = 0;
	SDL_Surface* surf_return = 0;

	if ((surf_temp = SDL_LoadBMP(file)) == 0){
		return 0;
	}

	surf_return = SDL_DisplayFormat(surf_temp);
	SDL_FreeSurface(surf_temp);

	return surf_return;
}

bool CSurface::OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y){
	if(surf_dest == 0 || surf_src == 0) return false; // Null pointers

	SDL_Rect dest_rect;

	dest_rect.x = x;
	dest_rect.y = y;

	SDL_BlitSurface(surf_src, 0, surf_dest, &dest_rect);

	return true;
}



bool CSurface::OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, 
			int x, int y, int x2, int y2, int w, int h)
{
	if(surf_dest == 0 || surf_src == 0) return false; // Null pointers

	SDL_Rect dest_rect;

	dest_rect.x = x;
	dest_rect.y = y;

	SDL_Rect src_rect;

	src_rect.x = x2;
	src_rect.y = y2;
	src_rect.w = w;
	src_rect.h = h;

	SDL_BlitSurface(surf_src, &src_rect, surf_dest, &dest_rect);

	return true;
}
