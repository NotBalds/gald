#pragma once

#include <Gald/Gald.hpp>
#include <bits/stdc++.h>
#include <ncurses.h>

using namespace std;

namespace Gald {
	class Sprite : public Object {
		string _filename;
	protected:
		void _update() {
			this->Object::_update();
			this->draw();
		}
	public:
		Sprite(int x, int y, string name, string filename) : Object(x, y, name), _filename(filename) {}
		void draw() {
			ifstream file;
			file.open(_filename);
			string line;
			int y = _absolute_y;
			while(getline(file, line)) {
				mvwprintw(stdscr, y, _absolute_x, "%s", line.c_str());
				y++;
			}
			file.close();
		}
	};
}
