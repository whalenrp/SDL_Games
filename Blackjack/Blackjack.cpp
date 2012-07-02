#include "Blackjack.h"
#include <iostream>


Blackjack::Blackjack(): running(true), endOfGame(false),
	surf_screen(0), surf_background(0),
	player1(), mDeck()
{}

void Blackjack::Reset(){
	player1.resetHand();
	dealer.resetHand();
	player1.addCard(mDeck.getNextCard());
	player1.addCard(mDeck.getNextCard());
	dealer.addCard(mDeck.getNextCard());
	dealer.addCard(mDeck.getNextCard());
	endOfGame = false;
	if (player1.getHandValue() == 21 || dealer.getHandValue() == 21){
		if (player1.getHandValue() == 21 && dealer.getHandValue() == 21);
		else if (player1.getHandValue() == 21)		
			player1.setMoney(player1.getMoney() + player1.getWager());
		else //  dealer.getHandValue() == 21
			player1.setMoney(player1.getMoney() - player1.getWager());
		finishRound();
	}
}

void Blackjack::finishRound(){
	int dealerHand = dealer.getHandValue();
	int playerHand = player1.getHandValue();

	// Player Bust
	if (playerHand > 21)
		player1.setMoney(player1.getMoney() - player1.getWager());
	// Player wins
	else if (dealerHand > 21 || playerHand > dealerHand)
		player1.setMoney(player1.getMoney() + player1.getWager());
	// Lost
	else if (playerHand != dealerHand)
		player1.setMoney(player1.getMoney() - player1.getWager());
	// Draw, do nothing.

	// Set board to be reset.
	endOfGame = true;
}

int Blackjack::onExecute(){
	if (onInit() == false){
		std::cout << "onInit failed" << std::endl;
		return -1;
	}

	SDL_Event event;

	while (running){
		while (SDL_PollEvent(&event)){
			OnEvent(&event);
		}

		SDL_Delay(50);
		onRender();
	}

	onCleanup();

	return 0;
}


int main(){
	Blackjack game;
	return game.onExecute();
}
