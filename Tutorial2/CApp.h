// These tutorials come from http://www.sdltutorials.com/sdl-tutorial-basics

#ifndef CAPP_H
#define CAPP_H

#include <SDL/SDL.h>
#include "CSurface.h"

class CApp{
	private:
		bool running;
	
		SDL_Surface* surf_display;
		SDL_Surface* surf_test;

	public:
		CApp();

		int OnExecute();

	public:
		bool OnInit();

		void OnEvent(SDL_Event* event);

		void OnLoop();

		void OnRender();

		void OnCleanup();
};

#endif
