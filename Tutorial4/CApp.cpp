#include "CApp.h"
#include <iostream>

CApp::CApp() :running(true), title(true), winner(GRID_TYPE_NONE), surf_display(0),
			board_size(3), surf_grid(0),
			surf_x(0), surf_o(0), surf_winning(0),
			surf_title(0), surf_draw(0),
			drip1(0), drip2(0), currentPlayer(0)
 
{
}

int CApp::OnExecute(){
	if (OnInit() == false) return -1;

	SDL_Event event;

	while (running){
		while (SDL_PollEvent(&event)){
			OnEvent(&event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

void CApp::Reset(){

	for (int i=0; i<board_size; ++i){
		for (int j=0; j<board_size; ++j)
			grid[j][i] = GRID_TYPE_NONE;
	}
	winner = 0;

}

void CApp::SetCell(int x, int y, int type){
	if (x < 0 || x >= board_size) return;
	if (y < 0 || y >= board_size) return;
	if (type < 0 || type > GRID_TYPE_O) return;

	grid[y][x] = type;
}

/*
 * Calculates if the given player is a winner
 * params:
 *  x		the x position of the new x/o added
 *  y		the y position of the new x/o added
 *  type	the player type (x's or o's)*/
bool CApp::isWinner(int x, int y, int type){
	int col, row, diag, rdiag;	
	col = row = diag = rdiag = 0;
	for (int i=0; i< board_size; ++i){
		if (grid[i][x] == type) ++col;
		if (grid[y][i] == type) ++row;
		if (grid[i][i] == type) ++diag;
		if (grid[i][board_size-1-i] == type) ++rdiag;
	}
	if ( col == board_size ||   row == board_size || 
		diag == board_size || rdiag == board_size)
		return true;
	else 
		return false;
}

bool CApp::isDraw(){
	if (winner == GRID_TYPE_O || winner == GRID_TYPE_X) return false;
	for (int i =0; i<board_size; ++i){
		for (int j =0; j<board_size; ++j){
			if (grid[j][i] == GRID_TYPE_NONE) return false;
		}
	}
	return true;
}

int main(){
	CApp theApp;
	return theApp.OnExecute();
}
