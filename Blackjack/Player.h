#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Card.h"
#include "CSurface.h"
#include <stdlib.h>
#include "SDL/SDL_ttf.h"

class Player{
	public:
		enum PlayerState{
			PLAYER_NONE,
			PLAYER_BUST,
			PLAYER_BLACKJACK
			};

		static const size_t CARD_HEIGHT = 160;
		static const size_t CARD_WIDTH = 115;
		static const size_t CARD_OFFSET = 80;
		static const size_t TEXT_STATUS_X = 150;
		static const size_t TEXT_STATUS_Y = CARD_HEIGHT + 10;

	private:
		static const size_t MAX_NUM_CARDS = 11;
		int handValue;
		size_t playerNumCards;
		size_t numAces;
		Card* playerCards[MAX_NUM_CARDS];
		PlayerState state;

	// Surfaces
	private:
		// Text
			SDL_Surface* surf_text_status;
			TTF_Font* font;

		// private function that will update the hand variables
		// based on the number of aces as well as the text 
		// associated with each hand.
		virtual int updateHandValue();
			
	public:
		Player();
		virtual ~Player();

		virtual bool onInit();
		virtual void resetHand();

		// returns the value of the hand and takes care of updating
		// the hand values.
		virtual void addCard(Card* const card);
		virtual void onDraw(SDL_Surface* surf_dest, int x, int y);
		virtual int getHandValue();
		virtual void onCleanup();

};

#endif
