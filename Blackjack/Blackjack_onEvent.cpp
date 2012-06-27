#include "Blackjack.h"

void Blackjack::OnEvent(SDL_Event* event){
	CEvent::OnEvent(event);
}

void Blackjack::OnExit(){
	running = false;
}

void Blackjack::OnLButtonDown(int mx, int my){
	player1.addCard(mDeck.getNextCard());
}

