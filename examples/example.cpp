#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include <unistd.h>
#include <Gald/Gald.hpp>
#include <Gald/Sounds.hpp>

using namespace std;

int main() {
	Gald::Object scene(0, 0, "Scene");
	Gald::Object object(1, 1, "Object");
	Gald::Sprite sprite(0, 0, "Sprite", "examples/spr.txt");
	Gald::Collider collider(0, 0, 14, 1, "Cld");

	object.add_child(&sprite);
	object.add_child(&collider);

	Gald::Object wall(10, 10, "Wall");
	Gald::Sprite wall_sprite(0, 0, "Wall Sprite", "examples/wall.txt");
	Gald::Collider wall_collider(0, 0, 12, 1, "Wall Collider");

	wall.add_child(&wall_sprite);
	wall.add_child(&wall_collider);

	Gald::SoundPlayer snd("examples/sound.wav");
	
	scene.add_child(&object);
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
			snd.play();
			Gald::DialogButton continue_but('o', "Continue", [](){});
			Gald::DialogButton exit_but('q', "Exit", [&win](){win.exit();});
			
			Gald::Dialog d("You died, continue?");
			d.add_button(&continue_but);
			d.add_button(&exit_but);
			d.start();
			object.set_x(0);
			object.set_y(0);
		}
		ch = win.get_event();
		usleep(5000);
	}
}
