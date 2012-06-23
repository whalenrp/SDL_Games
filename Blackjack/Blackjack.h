#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <SDL/SDL.h>
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "Challenger.h"
#include "Deck.h"

class Blackjack :public CEvent{

	// Surfaces
	private:
		bool running;
		SDL_Surface* surf_screen;
		SDL_Surface* surf_background;
		Challenger player1;
		Deck mDeck;

	public:

		void Reset();

	public:
		Blackjack();

		// if(TTF_Init()==-1)
		// 	return false;
		bool onInit();

		int onExecute();

		void onEvent();

			void onLButtonDown(int mx, int my);

		void onRender();

		// TTF_Quit();
		void onCleanup();

};

#endif
