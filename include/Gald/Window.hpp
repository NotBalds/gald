#pragma once

#include <Gald/Gald.hpp>
#include <ncurses.h>

using namespace std;

namespace Gald {
	class Window {
	private:
		Object* _root_object;
	public:
		Window(Object* root_object) : _root_object(root_object) {
			initscr();
			nodelay(stdscr, true);
			noecho();
		}
		~Window() {
			endwin();
		}
		void set_root_object(Object* obj) {
			_root_object = obj;
		}
		char get_event() {
			return getch();
		}
		void update() {
			clear();
			_root_object->_update();
		}
	};
}
