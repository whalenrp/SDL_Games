#ifndef DEALER_H
#define DEALER_H

#include "Blackjack.h"
#include "Player.h"

class Dealer : public Player{
	public:
		Dealer();
		~Dealer();

		void onInit();
		bool updateHand(Deck* deck);
		//void onDraw(int x, int y);
		void onCleanup();

};

#endif
