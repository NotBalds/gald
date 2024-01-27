#include <iostream>
#include <unistd.h>
#include <Gald/Gald.hpp>

using namespace std;

int main() {
	Gald::Object scene(0, 0, "Scene");
	Gald::Object object(0, 0, "Object");
	Gald::Sprite sprite(0, 0, "Sprite", "sprite.txt");
	Gald::Collider collider(0, 0, 9, 2, "Cld");

	if (scene.add_child(&object)) {
		throw "Add child error\n";
	}
	if (object.add_child(&sprite)) {
		throw "Add sprite error\n";
	}
	object.add_child(&collider);

	Gald::Object wall(10, 10, "Wall");
	Gald::Sprite wall_sprite(0, 0, "Wall Sprite", "wall.txt");
	Gald::Collider wall_collider(0, 0, 1, 5, "Wall Collider");

	wall.add_child(&wall_sprite);
	wall.add_child(&wall_collider);

	scene.add_child(&wall);
	
	Gald::Window win(&scene);

	char ch = win.get_event();
	while (ch != 'q') {
		win.update();
		int x = object.get_x();
		int y = object.get_y();
		if (ch == 'd')
			object.set_x(x + 1);
		if (ch == 'w')
			object.set_y(y - 1);
		if (ch == 'a')
			object.set_x(x - 1);
		if (ch == 's')
			object.set_y(y + 1);
		Gald::Collider* cld = dynamic_cast<Gald::Collider*>(object.get_child_by_name("Cld"));
		Gald::Collider* cld2 = dynamic_cast<Gald::Collider*>(wall.get_child_by_name("Wall Collider"));
		if (cld->is_colliding(*cld2)) {
			object.set_x(0);
			object.set_y(0);
		}
		ch = win.get_event();
		usleep(5000);
	}
}
