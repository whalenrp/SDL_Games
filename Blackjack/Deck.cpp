#include "Deck.h"
#include <cstdlib>
#include <ctime>

Deck::Deck(): cards(), curCard(0){}

Deck::~Deck(){}


// load all cards with blitted surfaces
bool Deck::onInit(){
	char h01[] = "./gfx/Cards/Classic/h01.png";
	char h02[] = "./gfx/Cards/Classic/h02.png";
	char h03[] = "./gfx/Cards/Classic/h03.png";
	char h04[] = "./gfx/Cards/Classic/h04.png";
	char h05[] = "./gfx/Cards/Classic/h05.png";
	char h06[] = "./gfx/Cards/Classic/h06.png";
	char h07[] = "./gfx/Cards/Classic/h07.png";
	char h08[] = "./gfx/Cards/Classic/h08.png";
	char h09[] = "./gfx/Cards/Classic/h09.png";
	char h10[] = "./gfx/Cards/Classic/h10.png";
	char h11[] = "./gfx/Cards/Classic/h11.png";
	char h12[] = "./gfx/Cards/Classic/h12.png";
	char h13[] = "./gfx/Cards/Classic/h13.png";
	char c01[] = "./gfx/Cards/Classic/c01.png";
	char c02[] = "./gfx/Cards/Classic/c02.png";
	char c03[] = "./gfx/Cards/Classic/c03.png";
	char c04[] = "./gfx/Cards/Classic/c04.png";
	char c05[] = "./gfx/Cards/Classic/c05.png";
	char c06[] = "./gfx/Cards/Classic/c06.png";
	char c07[] = "./gfx/Cards/Classic/c07.png";
	char c08[] = "./gfx/Cards/Classic/c08.png";
	char c09[] = "./gfx/Cards/Classic/c09.png";
	char c10[] = "./gfx/Cards/Classic/c10.png";
	char c11[] = "./gfx/Cards/Classic/c11.png";
	char c12[] = "./gfx/Cards/Classic/c12.png";
	char c13[] = "./gfx/Cards/Classic/c13.png";
	char d01[] = "./gfx/Cards/Classic/d01.png";
	char d02[] = "./gfx/Cards/Classic/d02.png";
	char d03[] = "./gfx/Cards/Classic/d03.png";
	char d04[] = "./gfx/Cards/Classic/d04.png";
	char d05[] = "./gfx/Cards/Classic/d05.png";
	char d06[] = "./gfx/Cards/Classic/d06.png";
	char d07[] = "./gfx/Cards/Classic/d07.png";
	char d08[] = "./gfx/Cards/Classic/d08.png";
	char d09[] = "./gfx/Cards/Classic/d09.png";
	char d10[] = "./gfx/Cards/Classic/d10.png";
	char d11[] = "./gfx/Cards/Classic/d11.png";
	char d12[] = "./gfx/Cards/Classic/d12.png";
	char d13[] = "./gfx/Cards/Classic/d13.png";
	char s01[] = "./gfx/Cards/Classic/s01.png";
	char s02[] = "./gfx/Cards/Classic/s02.png";
	char s03[] = "./gfx/Cards/Classic/s03.png";
	char s04[] = "./gfx/Cards/Classic/s04.png";
	char s05[] = "./gfx/Cards/Classic/s05.png";
	char s06[] = "./gfx/Cards/Classic/s06.png";
	char s07[] = "./gfx/Cards/Classic/s07.png";
	char s08[] = "./gfx/Cards/Classic/s08.png";
	char s09[] = "./gfx/Cards/Classic/s09.png";
	char s10[] = "./gfx/Cards/Classic/s10.png";
	char s11[] = "./gfx/Cards/Classic/s11.png";
	char s12[] = "./gfx/Cards/Classic/s12.png";
	char s13[] = "./gfx/Cards/Classic/s13.png";

	// If any of the images fails to load, return false
	if(((surf_card_ace_heart = CSurface::OnLoad(h01)) == 0)||
	((surf_card_2_heart = CSurface::OnLoad(h02)) == 0)||
	((surf_card_3_heart = CSurface::OnLoad(h03)) == 0)||
	((surf_card_4_heart = CSurface::OnLoad(h04)) == 0)||
	((surf_card_5_heart = CSurface::OnLoad(h05)) == 0)||
	((surf_card_6_heart = CSurface::OnLoad(h06)) == 0)||
	((surf_card_7_heart = CSurface::OnLoad(h07)) == 0)||
	((surf_card_8_heart = CSurface::OnLoad(h08)) == 0)||
	((surf_card_9_heart = CSurface::OnLoad(h09)) == 0)||
	((surf_card_10_heart = CSurface::OnLoad(h10)) == 0)||
	((surf_card_jack_heart = CSurface::OnLoad(h11)) == 0)||
	((surf_card_queen_heart = CSurface::OnLoad(h12)) == 0)||
	((surf_card_king_heart = CSurface::OnLoad(h13)) == 0)||
	((surf_card_ace_club = CSurface::OnLoad(c01)) == 0)||
	((surf_card_2_club = CSurface::OnLoad(c02)) == 0)||
	((surf_card_3_club = CSurface::OnLoad(c03)) == 0)||
	((surf_card_4_club = CSurface::OnLoad(c04)) == 0)||
	((surf_card_5_club = CSurface::OnLoad(c05)) == 0)||
	((surf_card_6_club = CSurface::OnLoad(c06)) == 0)||
	((surf_card_7_club = CSurface::OnLoad(c07)) == 0)||
	((surf_card_8_club = CSurface::OnLoad(c08)) == 0)||
	((surf_card_9_club = CSurface::OnLoad(c09)) == 0)||
	((surf_card_10_club = CSurface::OnLoad(c10)) == 0)||
	((surf_card_jack_club = CSurface::OnLoad(c11)) == 0)||
	((surf_card_queen_club = CSurface::OnLoad(c12)) == 0)||
	((surf_card_king_club = CSurface::OnLoad(c13)) == 0)||
	((surf_card_ace_diamond = CSurface::OnLoad(d01)) == 0)||
	((surf_card_2_diamond = CSurface::OnLoad(d02)) == 0)||
	((surf_card_3_diamond = CSurface::OnLoad(d03)) == 0)||
	((surf_card_4_diamond = CSurface::OnLoad(d04)) == 0)||
	((surf_card_5_diamond = CSurface::OnLoad(d05)) == 0)||
	((surf_card_6_diamond = CSurface::OnLoad(d06)) == 0)||
	((surf_card_7_diamond = CSurface::OnLoad(d07)) == 0)||
	((surf_card_8_diamond = CSurface::OnLoad(d08)) == 0)||
	((surf_card_9_diamond = CSurface::OnLoad(d09)) == 0)||
	((surf_card_10_diamond = CSurface::OnLoad(d10)) == 0)||
	((surf_card_jack_diamond = CSurface::OnLoad(d11)) == 0)||
	((surf_card_queen_diamond = CSurface::OnLoad(d12)) == 0)||
	((surf_card_king_diamond = CSurface::OnLoad(d13)) == 0)||
	((surf_card_ace_spade = CSurface::OnLoad(s01)) == 0)||
	((surf_card_2_spade = CSurface::OnLoad(s02)) == 0)||
	((surf_card_3_spade = CSurface::OnLoad(s03)) == 0)||
	((surf_card_4_spade = CSurface::OnLoad(s04)) == 0)||
	((surf_card_5_spade = CSurface::OnLoad(s05)) == 0)||
	((surf_card_6_spade = CSurface::OnLoad(s06)) = 0)||
	((surf_card_7_spade = CSurface::OnLoad(s07)) == 0)||
	((surf_card_8_spade = CSurface::OnLoad(s08)) == 0)||
	((surf_card_9_spade = CSurface::OnLoad(s09)) == 0)||
	((surf_card_10_spade = CSurface::OnLoad(s10)) == 0)||
	((surf_card_jack_spade = CSurface::OnLoad(s11)) == 0)||
	((surf_card_queen_spade = CSurface::OnLoad(s12)) == 0)||
	((surf_card_king_spade = CSurface::OnLoad(s13)) == 0))
		return false;

	cards.push_back(new Card(surf_card_ace_heart, Card::CARD_ACE));
	cards.push_back(new Card(surf_card_2_heart, Card::CARD_TWO));
	cards.push_back(new Card(surf_card_3_heart, Card::CARD_THREE));
	cards.push_back(new Card(surf_card_4_heart, Card::CARD_FOUR));
	cards.push_back(new Card(surf_card_5_heart, Card::CARD_FIVE));
	cards.push_back(new Card(surf_card_6_heart, Card::CARD_SIX));
	cards.push_back(new Card(surf_card_7_heart, Card::CARD_SEVEN));
	cards.push_back(new Card(surf_card_8_heart, Card::CARD_EIGHT));
	cards.push_back(new Card(surf_card_9_heart, Card::CARD_NINE));
	cards.push_back(new Card(surf_card_10_heart, Card::CARD_TEN));
	cards.push_back(new Card(surf_card_jack_heart, Card::CARD_JACK));
	cards.push_back(new Card(surf_card_queen_heart, Card::CARD_QUEEN));
	cards.push_back(new Card(surf_card_king_heart, Card::CARD_KING));
	cards.push_back(new Card(surf_card_ace_club, Card::CARD_ACE));
	cards.push_back(new Card(surf_card_2_club, Card::CARD_TWO));
	cards.push_back(new Card(surf_card_3_club, Card::CARD_THREE));
	cards.push_back(new Card(surf_card_4_club, Card::CARD_FOUR));
	cards.push_back(new Card(surf_card_5_club, Card::CARD_FIVE));
	cards.push_back(new Card(surf_card_6_club, Card::CARD_SIX));
	cards.push_back(new Card(surf_card_7_club, Card::CARD_SEVEN));
	cards.push_back(new Card(surf_card_8_club, Card::CARD_EIGHT));
	cards.push_back(new Card(surf_card_9_club, Card::CARD_NINE));
	cards.push_back(new Card(surf_card_10_club, Card::CARD_TEN));
	cards.push_back(new Card(surf_card_jack_club, Card::CARD_JACK));
	cards.push_back(new Card(surf_card_queen_club, Card::CARD_QUEEN));
	cards.push_back(new Card(surf_card_king_club, Card::CARD_KING));
	cards.push_back(new Card(surf_card_ace_diamond, Card::CARD_ACE));
	cards.push_back(new Card(surf_card_2_diamond, Card::CARD_TWO));
	cards.push_back(new Card(surf_card_3_diamond, Card::CARD_THREE));
	cards.push_back(new Card(surf_card_4_diamond, Card::CARD_FOUR));
	cards.push_back(new Card(surf_card_5_diamond, Card::CARD_FIVE));
	cards.push_back(new Card(surf_card_6_diamond, Card::CARD_SIX));
	cards.push_back(new Card(surf_card_7_diamond, Card::CARD_SEVEN));
	cards.push_back(new Card(surf_card_8_diamond, Card::CARD_EIGHT));
	cards.push_back(new Card(surf_card_9_diamond, Card::CARD_NINE));
	cards.push_back(new Card(surf_card_10_diamond, Card::CARD_TEN));
	cards.push_back(new Card(surf_card_jack_diamond, Card::CARD_JACK));
	cards.push_back(new Card(surf_card_queen_diamond, Card::CARD_QUEEN));
	cards.push_back(new Card(surf_card_king_diamond, Card::CARD_KING));
	cards.push_back(new Card(surf_card_ace_spade, Card::CARD_ACE));
	cards.push_back(new Card(surf_card_2_spade, Card::CARD_TWO));
	cards.push_back(new Card(surf_card_3_spade, Card::CARD_THREE));
	cards.push_back(new Card(surf_card_4_spade, Card::CARD_FOUR));
	cards.push_back(new Card(surf_card_5_spade, Card::CARD_FIVE));
	cards.push_back(new Card(surf_card_6_spade, Card::CARD_SIX));
	cards.push_back(new Card(surf_card_7_spade, Card::CARD_SEVEN));
	cards.push_back(new Card(surf_card_8_spade, Card::CARD_EIGHT));
	cards.push_back(new Card(surf_card_9_spade, Card::CARD_NINE));
	cards.push_back(new Card(surf_card_10_spade, Card::CARD_TEN));
	cards.push_back(new Card(surf_card_jack_spade, Card::CARD_JACK));
	cards.push_back(new Card(surf_card_queen_spade, Card::CARD_QUEEN));
	cards.push_back(new Card(surf_card_king_spade, Card::CARD_KING));
	
	return true;
}


// Shuffle cards (Reset & randomize)
void Deck::shuffle(){
	srand(time(0));
	for(int i=0; i< 52; ++i)
		std::swap(cards[i], cards[rand()%52]);	
	curCard = 0;
}


Card* const Deck::getNextCard(){
	if (curCard >= 52)
		shuffle();
	return cards[curCard++];
}


// clean up all cards.
// This must be called before the cards vector is erased.
void Deck::onCleanup(){
	SDL_FreeSurface(surf_card_ace_heart);
	SDL_FreeSurface(surf_card_2_heart);
	SDL_FreeSurface(surf_card_3_heart);
	SDL_FreeSurface(surf_card_4_heart);
	SDL_FreeSurface(surf_card_5_heart);
	SDL_FreeSurface(surf_card_6_heart);
	SDL_FreeSurface(surf_card_7_heart);
	SDL_FreeSurface(surf_card_8_heart);
	SDL_FreeSurface(surf_card_9_heart);
	SDL_FreeSurface(surf_card_10_heart);
	SDL_FreeSurface(surf_card_jack_heart);
	SDL_FreeSurface(surf_card_queen_heart);
	SDL_FreeSurface(surf_card_king_heart);
	SDL_FreeSurface(surf_card_ace_club);
	SDL_FreeSurface(surf_card_2_club);
	SDL_FreeSurface(surf_card_3_club);
	SDL_FreeSurface(surf_card_4_club);
	SDL_FreeSurface(surf_card_5_club);
	SDL_FreeSurface(surf_card_6_club);
	SDL_FreeSurface(surf_card_7_club);
	SDL_FreeSurface(surf_card_8_club);
	SDL_FreeSurface(surf_card_9_club);
	SDL_FreeSurface(surf_card_10_club);
	SDL_FreeSurface(surf_card_jack_club);
	SDL_FreeSurface(surf_card_queen_club);
	SDL_FreeSurface(surf_card_king_club);
	SDL_FreeSurface(surf_card_ace_diamond);
	SDL_FreeSurface(surf_card_2_diamond);
	SDL_FreeSurface(surf_card_3_diamond);
	SDL_FreeSurface(surf_card_4_diamond);
	SDL_FreeSurface(surf_card_5_diamond);
	SDL_FreeSurface(surf_card_6_diamond);
	SDL_FreeSurface(surf_card_7_diamond);
	SDL_FreeSurface(surf_card_8_diamond);
	SDL_FreeSurface(surf_card_9_diamond);
	SDL_FreeSurface(surf_card_10_diamond);
	SDL_FreeSurface(surf_card_jack_diamond);
	SDL_FreeSurface(surf_card_queen_diamond);
	SDL_FreeSurface(surf_card_king_diamond);
	SDL_FreeSurface(surf_card_ace_spade);
	SDL_FreeSurface(surf_card_2_spade);
	SDL_FreeSurface(surf_card_3_spade);
	SDL_FreeSurface(surf_card_4_spade);
	SDL_FreeSurface(surf_card_5_spade);
	SDL_FreeSurface(surf_card_6_spade);
	SDL_FreeSurface(surf_card_7_spade);
	SDL_FreeSurface(surf_card_8_spade);
	SDL_FreeSurface(surf_card_9_spade);
	SDL_FreeSurface(surf_card_10_spade);
	SDL_FreeSurface(surf_card_jack_spade);
	SDL_FreeSurface(surf_card_queen_spade);
	SDL_FreeSurface(surf_card_king_spade);

	for (	std::vector<Card*>::iterator it = cards.begin();
			it < cards.end();
			++it)
	{
		delete *it;
	}
}
