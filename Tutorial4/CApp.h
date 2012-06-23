// These tutorials come from http://www.sdltutorials.com/sdl-tutorial-basics

#ifndef CAPP_H
#define CAPP_H

#include <SDL/SDL.h>
#include "SDL/SDL_mixer.h"
#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent{
	// Game State vars
	private:
		bool running;

		bool title;

		/* GRID_TYPE_NONE = no winner
		 * GRID_TYPE_X = X wins
		 * GRID_TYPE_O = O wins
		 * if winner = -1, then we have a draw
		 */
		int winner;
	
		SDL_Surface* surf_display;

		const int board_size;

	// Surface vars
	private:
		SDL_Surface* surf_grid;
		SDL_Surface* surf_x;
		SDL_Surface* surf_o;
		SDL_Surface* surf_winning;
		SDL_Surface* surf_title;
		SDL_Surface* surf_draw;


	private:
		Mix_Chunk* drip1;
		Mix_Chunk* drip2;

	// More game state vars
	private:
		int grid[3][3];

		int currentPlayer;

		enum Type{
			GRID_TYPE_NONE=0,
			GRID_TYPE_X,
			GRID_TYPE_O
		};

	public:
		CApp();

		int OnExecute();

		void Reset();

		void SetCell(int x, int y, int type);

		bool isWinner(int x, int y, int type);

		bool isDraw();

	public:
		bool OnInit();

		void OnEvent(SDL_Event* event);

			void OnExit();

			void OnLButtonDown(int mx, int my);

		void OnLoop();

		void OnRender();

		void OnCleanup();
};

#endif
