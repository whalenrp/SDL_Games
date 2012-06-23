#include "CSurface.h"

CSurface::CSurface(){}

SDL_Surface* CSurface::OnLoad(char* file){
	SDL_Surface* tmp = 0;
	SDL_Surface* optimized = 0;

	if ((tmp = IMG_Load(file)) != 0){
		optimized = SDL_DisplayFormat(tmp);
		SDL_FreeSurface(tmp);
	}
	return optimized;
}

bool CSurface::OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y){
	if (surf_dest==0 || surf_src==0) return false; // invalid parameters

	SDL_Rect dest_rect;

	dest_rect.x = x;
	dest_rect.y = y;

	SDL_BlitSurface(surf_src, 0, surf_dest, &dest_rect);
	return true;
}


bool CSurface::OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, 
			int x, int y, int x2, int y2, int w, int h)
{
	if (surf_dest==0 || surf_src==0) return false; // invalid parameters

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
