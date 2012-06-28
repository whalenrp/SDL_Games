#include "Challenger.h"
#include <iostream>


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
	// Initialize base class.
	if (Player::onInit() == false) return false;

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
		((font = TTF_OpenFont("ttf/elsewher.ttf", 25))==0))
		return false;


	// set the text surfaces for initial wager and starting money.
	SDL_Color textColor = {0, 0, 0, 0};
	std::ostringstream o1;
	o1 << "Your wager: $";
	o1 << wager;
	surf_text_wager = TTF_RenderText_Solid(font, o1.str().c_str(), textColor);

	std::ostringstream o2;
	o2 << "Cash: $";
	o2 << money;
	surf_text_money = TTF_RenderText_Solid(font, o2.str().c_str(), textColor);
	return true;
}

void Challenger::onDraw(SDL_Surface* surf_dest, int x, int y){
	// Draws the cards stacked as well as the hand value
	Player::onDraw(surf_dest, x, y);

	// Draw the text fields for wager and money values.
	CSurface::OnDraw(surf_dest, 
		surf_text_wager, x + 300, y + 318 + 40);
	CSurface::OnDraw(surf_dest, 
		surf_text_money, x + 300, y + 318 + 65);

	// Draw the buttons based on the mouse click state
	CSurface::OnDraw(surf_dest, surf_chip10, x, y);
	CSurface::OnDraw(surf_dest, surf_chip5, x, y + 110);
	CSurface::OnDraw(surf_dest, surf_chip1, x, y + 220);

	CSurface::OnDraw(surf_dest, surf_hit_unpressed, x+50, y + 318 + 40);
	CSurface::OnDraw(surf_dest, surf_stand_unpressed, x+180, y+ 318 + 40);
}

void Challenger::onCleanup(){
	SDL_FreeSurface(surf_hit_pressed);
	SDL_FreeSurface(surf_hit_unpressed);
	SDL_FreeSurface(surf_stand_pressed);
	SDL_FreeSurface(surf_stand_unpressed);
	SDL_FreeSurface(surf_text_wager);
	SDL_FreeSurface(surf_text_money);
}
		

