#include "CApp.h"

void CApp::OnRender(){
	CSurface::OnDraw(surf_display, surf_grid, 0, 0);

	for (int i=0; i<3; ++i){
		for (int j=0; j<3; ++j){
			if (grid[j][i] == GRID_TYPE_X)
				CSurface::OnDraw(surf_display, surf_x, i*200, j*200);
			else if (grid[j][i] == GRID_TYPE_O)
				CSurface::OnDraw(surf_display, surf_o, i*200, j*200);
		}
	}

	switch (winner){
		case GRID_TYPE_O: // X wins
			CSurface::OnDraw(surf_display, surf_winning, 0, 0);
			CSurface::OnDraw(surf_display, surf_o, 80, 180);
			break;
		case GRID_TYPE_X: // X wins
			CSurface::OnDraw(surf_display, surf_winning, 0, 0);
			CSurface::OnDraw(surf_display, surf_x, 80, 180);
			break;
		case -1:
			CSurface::OnDraw(surf_display, surf_draw, 0, 0);
			break;
		default:;
	}

	if (title)
		CSurface::OnDraw(surf_display, surf_title, 0, 0);

	SDL_Flip(surf_display);
}
