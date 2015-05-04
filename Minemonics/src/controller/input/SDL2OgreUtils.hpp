#ifndef CONTROLLER_INPUT_SDL2OGREUTILS_HPP_
#define CONTROLLER_INPUT_SDL2OGREUTILS_HPP_

//# corresponding headers
//# forward declarations
//# system headers

//## controller headers
//## model headers
#include <SDL_keycode.h>
#include <SDL_mouse.h>
#include <SDL_stdinc.h>

//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
#include <controller/input/ApplicationKeycode.hpp>
#include <controller/input/ApplicationMousecode.hpp>

//## model headers
//## view headers
//## utils headers


/**
 * @brief		The SDL2 Ogre Utils help to convert between the keyboard and mouse definitions of each.
 * @details		Details
 * @date		2015-05-04
 * @author		Benjamin Ellenberger
 */
class SDL2OgreUtils {
public:
	static ApplicationMouseCode::MouseButton convert(Uint8 button)
	{
		switch (button) {
			case SDL_BUTTON_LEFT:
				return ApplicationMouseCode::LeftButton;
				break;

			case SDL_BUTTON_RIGHT:
				return ApplicationMouseCode::RightButton;
				break;

			case SDL_BUTTON_MIDDLE:
				return ApplicationMouseCode::MiddleButton;
				break;

			default:
				return ApplicationMouseCode::NoButton;
				break;
			}
			return ApplicationMouseCode::NoButton;
	}

	static Uint8 convert(ApplicationMouseCode::MouseButton button)
	{
		switch (button) {
			case ApplicationMouseCode::LeftButton:
				return SDL_BUTTON_LEFT;
				break;

			case ApplicationMouseCode::RightButton:
				return SDL_BUTTON_RIGHT;
				break;

			case ApplicationMouseCode::MiddleButton:
				return SDL_BUTTON_MIDDLE;
				break;

			default:
				return -1;
				break;
			}
			return -1;
	}

	static ApplicationKeycode::Keycode convert(SDL_Keycode key){
		switch (key) {
			case SDLK_1:
				return ApplicationKeycode::APPK_1;
				break;
			case SDLK_2:
				return ApplicationKeycode::APPK_2;
				break;
			case SDLK_3:
				return ApplicationKeycode::APPK_3;
				break;
			case SDLK_4:
				return ApplicationKeycode::APPK_4;
				break;
			case SDLK_5:
				return ApplicationKeycode::APPK_5;
				break;
			case SDLK_6:
				return ApplicationKeycode::APPK_6;
				break;
			case SDLK_7:
				return ApplicationKeycode::APPK_7;
				break;
			case SDLK_8:
				return ApplicationKeycode::APPK_8;
				break;
			case SDLK_9:
				return ApplicationKeycode::APPK_9;
				break;
			case SDLK_0:
				return ApplicationKeycode::APPK_0;
				break;

			case SDLK_q:
				return ApplicationKeycode::APPK_q;
				break;
			case SDLK_w:
				return ApplicationKeycode::APPK_w;
				break;
			case SDLK_e:
				return ApplicationKeycode::APPK_e;
				break;
			case SDLK_r:
				return ApplicationKeycode::APPK_r;
				break;
			case SDLK_t:
				return ApplicationKeycode::APPK_t;
				break;
			case SDLK_y:
				return ApplicationKeycode::APPK_y;
				break;
			case SDLK_u:
				return ApplicationKeycode::APPK_u;
				break;
			case SDLK_i:
				return ApplicationKeycode::APPK_i;
				break;
			case SDLK_o:
				return ApplicationKeycode::APPK_o;
				break;
			case SDLK_p:
				return ApplicationKeycode::APPK_p;
				break;
			case SDLK_a:
				return ApplicationKeycode::APPK_a;
				break;
			case SDLK_s:
				return ApplicationKeycode::APPK_s;
				break;
			case SDLK_d:
				return ApplicationKeycode::APPK_d;
				break;
			case SDLK_f:
				return ApplicationKeycode::APPK_f;
				break;
			case SDLK_g:
				return ApplicationKeycode::APPK_g;
				break;
			case SDLK_h:
				return ApplicationKeycode::APPK_h;
				break;
			case SDLK_j:
				return ApplicationKeycode::APPK_j;
				break;
			case SDLK_k:
				return ApplicationKeycode::APPK_k;
				break;
			case SDLK_l:
				return ApplicationKeycode::APPK_l;
				break;
			case SDLK_z:
				return ApplicationKeycode::APPK_z;
				break;
			case SDLK_x:
				return ApplicationKeycode::APPK_x;
				break;
			case SDLK_c:
				return ApplicationKeycode::APPK_c;
				break;
			case SDLK_v:
				return ApplicationKeycode::APPK_v;
				break;
			case SDLK_b:
				return ApplicationKeycode::APPK_b;
				break;
			case SDLK_n:
				return ApplicationKeycode::APPK_n;
				break;
			case SDLK_m:
				return ApplicationKeycode::APPK_m;
				break;

			case SDLK_COMMA:
				return ApplicationKeycode::APPK_COMMA;
				break;
			case SDLK_PERIOD:
				return ApplicationKeycode::APPK_PERIOD;
				break;
			case SDLK_SLASH:
				return ApplicationKeycode::APPK_SLASH;
				break;
			case SDLK_BACKSLASH:
				return ApplicationKeycode::APPK_BACKSLASH;
				break;
			case SDLK_MINUS:
				return ApplicationKeycode::APPK_MINUS;
				break;
			case SDLK_EQUALS:
				return ApplicationKeycode::APPK_EQUALS;
				break;
			case SDLK_SEMICOLON:
				return ApplicationKeycode::APPK_SEMICOLON;
				break;
			case SDLK_LEFTBRACKET:
				return ApplicationKeycode::APPK_LEFTBRACKET;
				break;
			case SDLK_RIGHTBRACKET:
				return ApplicationKeycode::APPK_RIGHTBRACKET;
				break;
			case SDLK_QUOTE:
				return ApplicationKeycode::APPK_QUOTE;
				break;
			case SDLK_BACKQUOTE:
				return ApplicationKeycode::APPK_BACKQUOTE;
				break;

			case SDLK_RETURN:
				return ApplicationKeycode::APPK_RETURN;
				break;
			case SDLK_SPACE:
				return ApplicationKeycode::APPK_SPACE;
				break;
			case SDLK_BACKSPACE:
				return ApplicationKeycode::APPK_BACKSPACE;
				break;
			case SDLK_TAB:
				return ApplicationKeycode::APPK_TAB;
				break;

			case SDLK_ESCAPE:
				return ApplicationKeycode::APPK_ESCAPE;
				break;
			case SDLK_PAUSE:
				return ApplicationKeycode::APPK_PAUSE;
				break;
			case SDLK_SYSREQ:
				return ApplicationKeycode::APPK_SYSREQ;
				break;
			case SDLK_POWER:
				return ApplicationKeycode::APPK_POWER;
				break;

				//case SDLK_NUMLOCK: return ApplicationKeycode::APPK_NUMLOCK;
				break;
			case SDLK_SCROLLLOCK:
				return ApplicationKeycode::APPK_SCROLLLOCK;
				break;

			case SDLK_F1:
				return ApplicationKeycode::APPK_F1;
				break;
			case SDLK_F2:
				return ApplicationKeycode::APPK_F2;
				break;
			case SDLK_F3:
				return ApplicationKeycode::APPK_F3;
				break;
			case SDLK_F4:
				return ApplicationKeycode::APPK_F4;
				break;
			case SDLK_F5:
				return ApplicationKeycode::APPK_F5;
				break;
			case SDLK_F6:
				return ApplicationKeycode::APPK_F6;
				break;
			case SDLK_F7:
				return ApplicationKeycode::APPK_F7;
				break;
			case SDLK_F8:
				return ApplicationKeycode::APPK_F8;
				break;
			case SDLK_F9:
				return ApplicationKeycode::APPK_F9;
				break;
			case SDLK_F10:
				return ApplicationKeycode::APPK_F10;
				break;
			case SDLK_F11:
				return ApplicationKeycode::APPK_F11;
				break;
			case SDLK_F12:
				return ApplicationKeycode::APPK_F12;
				break;
			case SDLK_F13:
				return ApplicationKeycode::APPK_F13;
				break;
			case SDLK_F14:
				return ApplicationKeycode::APPK_F14;
				break;
			case SDLK_F15:
				return ApplicationKeycode::APPK_F15;
				break;

			case SDLK_LCTRL:
				return ApplicationKeycode::APPK_LCTRL;
				break;
			case SDLK_LALT:
				return ApplicationKeycode::APPK_LALT;
				break;
			case SDLK_LSHIFT:
				return ApplicationKeycode::APPK_LSHIFT;
				break;
				//case SDLK_LSUPER: return APPK_LeftWindows;
				break;
			case SDLK_RCTRL:
				return ApplicationKeycode::APPK_RCTRL;
				break;
			case SDLK_RALT:
				return ApplicationKeycode::APPK_RALT;
				break;
			case SDLK_RSHIFT:
				return ApplicationKeycode::APPK_RSHIFT;
				break;
				//case SDLK_RSUPER: return APPK_RightWindows;
				break;
			case SDLK_MENU:
				return ApplicationKeycode::APPK_MENU;
				break;

			case SDLK_KP_0:
				return ApplicationKeycode::APPK_KP_0;
				break;
			case SDLK_KP_1:
				return ApplicationKeycode::APPK_KP_1;
				break;
			case SDLK_KP_2:
				return ApplicationKeycode::APPK_KP_2;
				break;
			case SDLK_KP_3:
				return ApplicationKeycode::APPK_KP_3;
				break;
			case SDLK_KP_4:
				return ApplicationKeycode::APPK_KP_4;
				break;
			case SDLK_KP_5:
				return ApplicationKeycode::APPK_KP_5;
				break;
			case SDLK_KP_6:
				return ApplicationKeycode::APPK_KP_6;
				break;
			case SDLK_KP_7:
				return ApplicationKeycode::APPK_KP_7;
				break;
			case SDLK_KP_8:
				return ApplicationKeycode::APPK_KP_8;
				break;
			case SDLK_KP_9:
				return ApplicationKeycode::APPK_KP_9;
				break;
			case SDLK_KP_PERIOD:
				return ApplicationKeycode::APPK_KP_PERIOD;
				break;
			case SDLK_KP_PLUS:
				return ApplicationKeycode::APPK_KP_PLUS;
				break;
			case SDLK_KP_MINUS:
				return ApplicationKeycode::APPK_KP_MINUS;
				break;
			case SDLK_KP_MULTIPLY:
				return ApplicationKeycode::APPK_KP_MULTIPLY;
				break;
			case SDLK_KP_DIVIDE:
				return ApplicationKeycode::APPK_KP_DIVIDE;
				break;
			case SDLK_KP_ENTER:
				return ApplicationKeycode::APPK_KP_ENTER;
				break;

			case SDLK_UP:
				return ApplicationKeycode::APPK_UP;
				break;
			case SDLK_LEFT:
				return ApplicationKeycode::APPK_LEFT;
				break;
			case SDLK_RIGHT:
				return ApplicationKeycode::APPK_RIGHT;
				break;
			case SDLK_DOWN:
				return ApplicationKeycode::APPK_DOWN;
				break;

			case SDLK_HOME:
				return ApplicationKeycode::APPK_HOME;
				break;
			case SDLK_END:
				return ApplicationKeycode::APPK_END;
				break;
			case SDLK_PAGEUP:
				return ApplicationKeycode::APPK_PAGEUP;
				break;
			case SDLK_PAGEDOWN:
				return ApplicationKeycode::APPK_PAGEDOWN;
				break;
			case SDLK_INSERT:
				return ApplicationKeycode::APPK_INSERT;
				break;
			case SDLK_DELETE:
				return ApplicationKeycode::APPK_DELETE;
				break;
			}
			return ApplicationKeycode::APPK_UNKNOWN;
	}

	//static SDL_Keycode convert(ApplicationKeycode::Keycode key);
};

#endif /* CONTROLLER_INPUT_SDL2OGREUTILS_HPP_ */