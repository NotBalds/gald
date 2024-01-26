#include <iostream>
#include <unistd.h>
#include <Gald/Gald.hpp>

using namespace std;

int main() {
	Gald::Object scene(0, 0, "Scene");
	Gald::Object object(0, 2, "Object");
	Gald::Sprite sprite(4, 0, "Sprite", "sprite.txt");

	if (scene.add_child(&object)) {
		throw "Add child error\n";
	}
	if (object.add_child(&sprite)) {
		throw "Add sprite error\n";
	}
	
	Gald::Window win(&scene);

	char ch = win.get_event();
	while (ch != 'q') {
		win.update();
		int x = sprite.get_x();
		int y = sprite.get_y();
		if (ch == 'd')
			sprite.set_x(x + 1);
		if (ch == 'w')
			sprite.set_y(y - 1);
		if (ch == 'a')
			sprite.set_x(x - 1);
		if (ch == 's')
			sprite.set_y(y + 1);
		ch = win.get_event();
		usleep(5000);
	}
}
