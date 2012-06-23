#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "CSurface.h"
#include <vector>

class Deck{
	private:

		SDL_Surface* surf_card_ace_heart;
		SDL_Surface* surf_card_2_heart;
		SDL_Surface* surf_card_3_heart;
		SDL_Surface* surf_card_4_heart;
		SDL_Surface* surf_card_5_heart;
		SDL_Surface* surf_card_6_heart;
		SDL_Surface* surf_card_7_heart;
		SDL_Surface* surf_card_8_heart;
		SDL_Surface* surf_card_9_heart;
		SDL_Surface* surf_card_10_heart;
		SDL_Surface* surf_card_jack_heart;
		SDL_Surface* surf_card_queen_heart;
		SDL_Surface* surf_card_king_heart;
		SDL_Surface* surf_card_ace_club;
		SDL_Surface* surf_card_2_club;
		SDL_Surface* surf_card_3_club;
		SDL_Surface* surf_card_4_club;
		SDL_Surface* surf_card_5_club;
		SDL_Surface* surf_card_6_club;
		SDL_Surface* surf_card_7_club;
		SDL_Surface* surf_card_8_club;
		SDL_Surface* surf_card_9_club;
		SDL_Surface* surf_card_10_club;
		SDL_Surface* surf_card_jack_club;
		SDL_Surface* surf_card_queen_club;
		SDL_Surface* surf_card_king_club;
		SDL_Surface* surf_card_ace_diamond;
		SDL_Surface* surf_card_2_diamond;
		SDL_Surface* surf_card_3_diamond;
		SDL_Surface* surf_card_4_diamond;
		SDL_Surface* surf_card_5_diamond;
		SDL_Surface* surf_card_6_diamond;
		SDL_Surface* surf_card_7_diamond;
		SDL_Surface* surf_card_8_diamond;
		SDL_Surface* surf_card_9_diamond;
		SDL_Surface* surf_card_10_diamond;
		SDL_Surface* surf_card_jack_diamond;
		SDL_Surface* surf_card_queen_diamond;
		SDL_Surface* surf_card_king_diamond;
		SDL_Surface* surf_card_ace_spade;
		SDL_Surface* surf_card_2_spade;
		SDL_Surface* surf_card_3_spade;
		SDL_Surface* surf_card_4_spade;
		SDL_Surface* surf_card_5_spade;
		SDL_Surface* surf_card_6_spade;
		SDL_Surface* surf_card_7_spade;
		SDL_Surface* surf_card_8_spade;
		SDL_Surface* surf_card_9_spade;
		SDL_Surface* surf_card_10_spade;
		SDL_Surface* surf_card_jack_spade;
		SDL_Surface* surf_card_queen_spade;
		SDL_Surface* surf_card_king_spade;

	public:
		Deck();
		~Deck();

		// load all cards with blitted surfaces
		bool onInit();

		// Shuffle cards (randomize)
		void shuffle();

		const Card* getNextCard();

		// clean up all cards.
		// This must be called before the cards vector is erased.
		void onCleanup();
	
	private:
		std::vector<Card*> cards;
		size_t curCard;
};

#endif
