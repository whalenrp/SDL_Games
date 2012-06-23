// These tutorials come from http://www.sdltutorials.com/sdl-tutorial-basics

#ifndef CAPP_H
#define CAPP_H

#include <SDL/SDL.h>

class CApp{
	private:
		bool running;
	
		SDL_Surface* surf_display;

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
