#ifndef CHALLENGER_H
#define CHALLENGER_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Player.h"
#include <sstream>

class Challenger : public Player {
	//Layout UI values
	public:
		static const int TEXT_WAGER_X = 300;
		static const int TEXT_WAGER_Y = Player::CARD_HEIGHT + 40;
		static const int TEXT_MONEY_X = 300;
		static const int TEXT_MONEY_Y = Player::CARD_HEIGHT + 65;
		static const int CHIP_5_Y = 60;
		static const int CHIP_1_Y = 2*CHIP_5_Y;
		static const int HIT_X = 80;
		static const int HIT_Y = Player::CARD_HEIGHT + 40;
		static const int STAND_X = 180;
		static const int STAND_Y = HIT_Y;

		// Button sizes in pixels used for mouse click events
		static const int HIT_WIDTH = 75;
		static const int HIT_HEIGHT = 38;
		static const int STND_WIDTH = 75;
		static const int STND_HEIGHT = 38;

		static const int CHIP_WIDTH = 50;// square chips (width = height)


	private: 
		int wager;
		int money;
	private:
		/*enum Chip{
			CHIP_ONE,
			CHIP_FIVE,
			CHIP_TEN};*/

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
		int getMoney();
		void setMoney(int val);
		int getWager();
		void setWager(int val);
		void onCleanup();
		
};

#endif
