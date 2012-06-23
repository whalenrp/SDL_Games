#include "CApp.h"

CApp::CApp(){
	surf_display = 0;
	running = true;
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

int main(){
	CApp theApp;
	return theApp.OnExecute();
}
