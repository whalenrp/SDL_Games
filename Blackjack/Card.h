#ifndef CARD_H
#define CARD_H

#include <SDL/SDL.h>

class Card{
	public:
		enum Type{
			CARD_ACE = 1,
			CARD_TWO,
			CARD_THREE,
			CARD_FOUR,
			CARD_FIVE,
			CARD_SIX,
			CARD_SEVEN,
			CARD_EIGHT,
			CARD_NINE,
			CARD_TEN,
			CARD_JACK,
			CARD_QUEEN,
			CARD_KING};

		Card(SDL_Surface* card, const Type type);
		Card(const Card& card);
		~Card();

		int getValue() const;

		bool draw(SDL_Surface* surf_dest, int x, int y) const ;

	private:
		Card();
		SDL_Surface* surf_card;
		Type mType;
};


#endif
