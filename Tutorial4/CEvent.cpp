
#include "CEvent.h"

CEvent::CEvent(){}

CEvent::~CEvent(){}

void CEvent::OnEvent(SDL_Event* event){
	switch(event->type){
		case SDL_ACTIVEEVENT:{
		switch(event->active.state) {
                case SDL_APPMOUSEFOCUS: {
                    if ( event->active.gain )    OnMouseFocus();
                    else                OnMouseBlur();
 
                    break;
                }
                case SDL_APPINPUTFOCUS: {
                    if ( event->active.gain )    OnInputFocus();
                    else                OnInputBlur();
 
                    break;
                }
                case SDL_APPACTIVE:    {
                    if ( event->active.gain )    OnRestore();
                    else                OnMinimize();
 
                    break;
                }
            }
            break;
        }
 
        case SDL_KEYDOWN: {
            OnKeyDown(event->key.keysym.sym,event->key.keysym.mod,event->key.keysym.unicode);
            break;
        }
 
        case SDL_KEYUP: {
            OnKeyUp(event->key.keysym.sym,event->key.keysym.mod,event->key.keysym.unicode);
            break;
        }
 
        case SDL_MOUSEMOTION: {
            OnMouseMove(event->motion.x,event->motion.y,event->motion.xrel,event->motion.yrel,(event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
            break;
        }
 
        case SDL_MOUSEBUTTONDOWN: {
            switch(event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonDown(event->button.x,event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonDown(event->button.x,event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonDown(event->button.x,event->button.y);
                    break;
                }
            }
            break;
        }
 
        case SDL_MOUSEBUTTONUP:    {
            switch(event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonUp(event->button.x,event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonUp(event->button.x,event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonUp(event->button.x,event->button.y);
                    break;
                }
            }
            break;
        }
 
        case SDL_JOYAXISMOTION: {
            OnJoyAxis(event->jaxis.which,event->jaxis.axis,event->jaxis.value);
            break;
        }
 
        case SDL_JOYBALLMOTION: {
            OnJoyBall(event->jball.which,event->jball.ball,event->jball.xrel,event->jball.yrel);
            break;
        }
 
        case SDL_JOYHATMOTION: {
            OnJoyHat(event->jhat.which,event->jhat.hat,event->jhat.value);
            break;
        }
        case SDL_JOYBUTTONDOWN: {
            OnJoyButtonDown(event->jbutton.which,event->jbutton.button);
            break;
        }
 
        case SDL_JOYBUTTONUP: {
            OnJoyButtonUp(event->jbutton.which,event->jbutton.button);
            break;
        }
 
        case SDL_QUIT: {
            OnExit();
            break;
        }
 
        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }
 
        case SDL_VIDEORESIZE: {
            OnResize(event->resize.w,event->resize.h);
            break;
        }
 
        case SDL_VIDEOEXPOSE: {
            OnExpose();
            break;
        }
 
        default: {
            OnUser(event->user.type,event->user.code,event->user.data1,event->user.data2);
            break;
        }
    }
}
/*
virtual void OnInputFocus();

virtual void OnInputBlur();

virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

virtual void OnMouseFocus();

virtual void OnMouseMove(int mX, int mY, int relX, int relY,
		bool left, bool right, bool middle);

virtual void OnLButtonDown(int mX, int mY);
 
virtual void OnLButtonUp(int mX, int mY);
 
virtual void OnRButtonDown(int mX, int mY);
 
virtual void OnRButtonUp(int mX, int mY);
 
virtual void OnMButtonDown(int mX, int mY);
 
virtual void OnMButtonUp(int mX, int mY);
 
virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
 
virtual void OnJoyButtonDown(Uint8 which, Uint8 button);
 
virtual void OnJoyButtonUp(Uint8 which, Uint8 button);
 
virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);
 
virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
 
virtual void OnMinimize();
 
virtual void OnRestore();
 
virtual void OnResize(int w,int h);
 
virtual void OnExpose();
 
virtual void OnExit();
 
virtual void OnUser(Uint8 type, int code, void* data1, void* data2)*/

