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

	while (win.get_event() != 'q') {
		win.update();
		usleep(5000);
	}
}
