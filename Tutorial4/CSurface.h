#ifndef CSURFACE_H
#define CSURFACE_H

#include <SDL/SDL.h>

class CSurface{
	public:
		CSurface();

	public:
		static SDL_Surface* OnLoad(char* file);

		static bool OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, 
				int x, int y);

		static bool OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, 
				int x, int y, int x2, int y2, int w, int h);

		static bool Transparent(SDL_Surface* surf_dest, int r, int g, int b);
};

#endif
