#include "Blackjack.h"
#include <iostream>


Blackjack::Blackjack(): running(true),
	surf_screen(0), surf_background(0),
	player1(), mDeck()
{}

void Blackjack::Reset(){
	player1.resetHand();
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

		onRender();
	}

	onCleanup();

	return 0;
}


int main(){
	Blackjack game;
	return game.onExecute();
}
