#include "Blackjack.h"


Blackjack::Blackjack(): running(true),
	surf_screen(0), surf_background(0),
	player1(), mDeck()
{}

void Blackjack::Reset(){
	player1.resetHand();
}

int Blackjack::onExecute(){
	if (OnInit() == false) return -1;

	SDL_Event event;

	while (running){
		while (SDL_PollEvent(&event)){
			onEvent(&event);
		}

		onLoop();
		onRender();
	}

	onCleanup();

	return 0;
}


int main(){
	Blackjack game;
	return game.onExecute();
}
