#include "Challenger.h"


Challenger::Challenger(): Player(), 
		wager(1), money(200),
		surf_hit_pressed(0), surf_hit_unpressed(0),
		surf_stand_pressed(0), surf_stand_unpressed(0),
		surf_chip10(0), surf_chip5(0), surf_chip1(0),
		surf_text_wager(0), surf_text_money(0)
		//sfx_button(0), sfx_chip(0)
{}


Challenger::~Challenger(){}

bool Challenger::onInit(){
	char hp[] = "./gfx/hit_pressed.png";
	char hu[] = "./gfx/hit_unpressed.png";
	char sp[] = "./gfx/stand_pressed.png";
	char su[] = "./gfx/stand_unpressed.png";
	char chip10[] = "./gfx/chip_10.png";
	char chip5[] = "./gfx/chip_5.png";
	char chip1[] = "./gfx/chip_1.png";
	// Load surfaces. Return false if any fail to load
	if (((surf_hit_unpressed = CSurface::OnLoad(hu))==0) ||
		((surf_hit_pressed = CSurface::OnLoad(hp))==0) ||
		((surf_stand_pressed = CSurface::OnLoad(sp))==0) ||
		((surf_stand_unpressed = CSurface::OnLoad(su))==0)||
		((surf_chip10 = CSurface::OnLoad(chip10))==0) ||
		((surf_chip5 = CSurface::OnLoad(chip5))==0) ||
		((surf_chip1 = CSurface::OnLoad(chip1))==0) ||
		((font = TTF_OpenFont("ttf/elsewher.ttf", 16))==0))
		return false;

	// set the text surfaces for initial wager and starting money.
	SDL_Color textColor = {.r=0, .g=0, .b=0, .unused=0};
	std::ostringstream o;
	o << wager;
	surf_text_wager = TTF_RenderText_Solid(font, o.str().c_str(), textColor);

	o << money;
	surf_text_money = TTF_RenderText_Solid(font, o.str().c_str(), textColor);
	return true;
}

void Challenger::onDraw(SDL_Surface* surf_dest, int x, int y){
	// Draws the cards stacked as well as the hand value
	Player::onDraw(surf_dest, x, y);

	// Draw the text fields for wager and money values.
	CSurface::OnDraw(surf_dest, 
		surf_text_wager, x + Player::CARD_WIDTH, y + Player::CARD_HEIGHT + 20);
	CSurface::OnDraw(surf_dest, 
		surf_text_money, x + Player::CARD_WIDTH, y + Player::CARD_HEIGHT + 30);

	// Draw the buttons based on the mouse click state
	CSurface::OnDraw(surf_dest, surf_chip10, x, y);
	CSurface::OnDraw(surf_dest, surf_chip5, x, y + 30);
	CSurface::OnDraw(surf_dest, surf_chip1, x, y + 60);

	CSurface::OnDraw(surf_dest, surf_hit_unpressed, x, y + Player::CARD_HEIGHT);
	CSurface::OnDraw(surf_dest, surf_stand_unpressed, x+100, y+Player::CARD_HEIGHT);
}

void Challenger::onCleanup(){
	SDL_FreeSurface(surf_hit_pressed);
	SDL_FreeSurface(surf_hit_unpressed);
	SDL_FreeSurface(surf_stand_pressed);
	SDL_FreeSurface(surf_stand_unpressed);
	SDL_FreeSurface(surf_text_wager);
	SDL_FreeSurface(surf_text_money);
}
		

