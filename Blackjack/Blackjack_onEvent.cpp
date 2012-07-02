#include "Blackjack.h"
#include <iostream>

void Blackjack::OnEvent(SDL_Event* event){
	CEvent::OnEvent(event);
}

void Blackjack::OnExit(){
	running = false;
}

void Blackjack::OnLButtonDown(int mx, int my){
	if (endOfGame){
		Reset();
		return;
	}
	int hitx = play_1_x + Challenger::HIT_X;
	int hity = play_1_y + Challenger::HIT_Y;
	int standx = play_1_x + Challenger::STAND_X;
	int standy = play_1_y + Challenger::STAND_Y;

	// Clicked the hit button
	if ( hitx < mx && mx < hitx + Challenger::HIT_WIDTH &&
		 hity < my && my < hity + Challenger::HIT_HEIGHT)
	{
		player1.addCard(mDeck.getNextCard());
		// check for bust
		if (player1.getHandValue() > 21) finishRound();	
	}

	// Clicked the stand button
	if ( standx < mx && mx < standx + Challenger::STND_WIDTH &&
		 standy < my && my < standy + Challenger::STND_HEIGHT)
	{
		while (dealer.getHandValue() < 17)
			dealer.addCard(mDeck.getNextCard());

		finishRound();
	}

	// clicked in the chip region
	if ( play_1_x < mx && mx < play_1_x + Challenger::CHIP_WIDTH &&
		 play_1_y < my && my < play_1_y + Challenger::CHIP_1_Y + Challenger::CHIP_WIDTH)
	{
		// Clicked ten chip
		if (my < play_1_y + Challenger::CHIP_WIDTH){
			player1.setWager(10);
		}

		// Clicked five chip
		int chip5y = play_1_y + Challenger::CHIP_5_Y;
		if (chip5y < my && my < chip5y + Challenger::CHIP_WIDTH){
			player1.setWager(5);
		}

		//Clicked ones chip
		int chip1y = play_1_y + Challenger::CHIP_1_Y;
		if (chip1y < my && 	my < chip1y + Challenger::CHIP_WIDTH){
			player1.setWager(1);
		}
	}
}

