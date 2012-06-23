#ifndef CHALLENGER_H
#define CHALLENGER_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Player.h"
#include <sstream>

class Challenger : private Player {
	private: 
		size_t wager;
		int money;
	private:
		enum Chip{
			CHIP_ONE,
			CHIP_FIVE,
			CHIP_TEN};

	private:
		//Buttons
			SDL_Surface* surf_hit_pressed;
			//SDL_Surface* surf_hit_hover;
			SDL_Surface* surf_hit_unpressed;
			SDL_Surface* surf_stand_pressed;
			//SDL_Surface* surf_stand_hover;
			SDL_Surface* surf_stand_unpressed;
		
		// Chips
			SDL_Surface* surf_chip10;
			SDL_Surface* surf_chip5;
			SDL_Surface* surf_chip1;

		// Text fields
			SDL_Surface* surf_text_wager;
			TTF_Font* font;
			SDL_Surface* surf_text_money;

	// Sounds
	private:
		// SFX
			//Mix_Chunk* sfx_button;
			//Mix_Chunk* sfx_chip;

	public:
		Challenger();
		~Challenger();

		bool onInit();
		void onDraw(SDL_Surface* surf_dest, int x, int y) ;
		void onCleanup();
		
};

#endif
