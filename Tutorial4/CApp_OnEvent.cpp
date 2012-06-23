#include "CApp.h"

void CApp::OnEvent(SDL_Event* event){
	CEvent::OnEvent(event);
}

void CApp::OnExit(){
	running = false;
}

void CApp::OnLButtonDown(int mx, int my){
	int x = mx/200;
	int y = my/200;

	if (title == true){
		title = false;
		return;
	}

	// If game over, reset
	if (winner != GRID_TYPE_NONE){
		Reset();
		return;
	}

	// Clicked square already filled.
	if (grid[y][x] != GRID_TYPE_NONE) return;

	// Clicked valid square, so fill it.
	if (currentPlayer == 0){
		SetCell(x, y, GRID_TYPE_X);
		Mix_PlayChannel(-1, drip1, 0);
		if (isWinner(x, y, GRID_TYPE_X))
			winner = GRID_TYPE_X;
	}
	else{
		SetCell(x, y, GRID_TYPE_O);
		Mix_PlayChannel(-1, drip2, 0);
		if (isWinner(x, y, GRID_TYPE_O))
			winner = GRID_TYPE_O;
	}

	//Check for draw
	if (isDraw())
		winner = -1;
		
		
	// Switch players (Loser goes first, or just continue game)
	currentPlayer = (currentPlayer+1)%2;
}
