#pragma once 

#include <bits/stdc++.h>
#include <Gald/Gald.hpp>

using namespace std;

namespace Gald {
	class Collider : public Object {
	private:
		int _width, _height;
	public:
		Collider(int x, int y, int width, int height, string name) : Object(x, y, name), _width(width), _height(height) {}
		bool is_colliding(Collider cld) {
			int x1 = _absolute_x;
			int y1 = _absolute_y;
			int x2 = cld.get_absolute_x();
			int y2 = cld.get_absolute_y();
			int w1 = _width;
			int h1 = _height;
			int w2 = cld.get_width();
			int h2 = cld.get_height();
			return ((x1 < (x2 + w2)) && ((x1 + w1) > x2)) && ((y1 < (y2 + h2)) && ((y1 + h1) > y2));	
		}

		int get_height() { return _height; }
		int get_width() { return _width; }
	};
}
