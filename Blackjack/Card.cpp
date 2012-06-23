#include "Card.h"
#include "CSurface.h"

Card::Card(SDL_Surface* card, const Type type) :
		surf_card(card), mType(type){}

Card::Card(const Card& card): 
		surf_card(card.surf_card), mType(card.mType){}

Card::~Card(){}

int Card::getValue() const {	
	return mType;
}


bool Card::draw(SDL_Surface* surf_dest, int x, int y) const {
		return CSurface::OnDraw(surf_dest, surf_card, x, y);
}

