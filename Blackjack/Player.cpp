#include "Player.h"
#include <sstream>
#include <algorithm>
#include <iostream>


Player::Player(): handValue(0), playerNumCards(0),
	numAces(0),state(PLAYER_NONE), surf_text_status(0), font(0){}

Player::~Player(){}

bool Player::onInit(){
	if ((font = TTF_OpenFont("ttf/elsewher.ttf", 30)) == 0)
		return false;
	SDL_Color textColor = {0, 0, 0, 0};
	std::ostringstream o;
	o << handValue;
	surf_text_status = TTF_RenderText_Solid(font, o.str().c_str(), textColor);
	return true;
} 

void Player::resetHand(){
	for(size_t i=0; i< playerNumCards; ++i)
		playerCards[i] = 0;
	playerNumCards = 0;
	handValue = 0;
	numAces = 0;
	state = PLAYER_NONE;
	getHandValue();
}

void Player::addCard(Card* const card){
	if (playerNumCards >= MAX_NUM_CARDS)
		throw playerNumCards;

	playerCards[playerNumCards] = card;
	
	// The values increase up to 13 for the king.
	// modding the value by 11 will make jack,queen, and king go to 10
	handValue += std::min(10,card->getValue());

	if (card->getValue() == Card::CARD_ACE){
		++numAces;
		// hand value has already been increased by 1, so just add 10
		handValue = handValue + 10;
	}

	++playerNumCards;

	// update hand value and text displayed
	updateHandValue();
}


int Player::updateHandValue(){
	SDL_Color textColor = {0, 0, 0, 0};
	if (handValue < 21){
		// display the value of the hand in the text
		std::ostringstream o;
		o << handValue;
		surf_text_status = TTF_RenderText_Solid(font, o.str().c_str(), textColor);
		return handValue;
	}
	else if (handValue == 21){
		state = PLAYER_BLACKJACK;
		surf_text_status = TTF_RenderText_Solid(font, "Blackjack!", textColor);
		return handValue;
	}
	// else over 21. 
	// first check for aces and change them to 1s
	else if (numAces > 0){
		handValue = handValue - 10;
		--numAces;
		return updateHandValue();
	}
	// The hand has gone over.
	else{
		state = PLAYER_BUST;
		surf_text_status = TTF_RenderText_Solid(
			font, 
			"Bust!", 
			textColor);
		return handValue;
	}
}

void Player::onDraw(SDL_Surface* surf_dest, int x, int y){
	// Draw all the cards stacked skewed on top of eachother, 
	// newer cards appearing on top of the stack.
	for (size_t i=0; i< playerNumCards; ++i){
		// 30px increment down x for each card.
		playerCards[i]->draw(surf_dest, x+(30*i) + CARD_OFFSET, y);
	}

	// Draw the text for the hand value underneath the cards
	if (handValue !=0)
		CSurface::OnDraw(
			surf_dest, surf_text_status, x + TEXT_STATUS_X, y + TEXT_STATUS_Y);
}

int Player::getHandValue(){
	return handValue;
}

void Player::onCleanup(){
	SDL_FreeSurface(surf_text_status);
	TTF_CloseFont(font);
}

