#pragma once

#include <Gald/Gald.hpp>
#include <ncurses.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

namespace Gald {
	class Dialog;

	class DialogButton {
	friend class Dialog;
	private:
		char _key;
		string _action;
		function<void()> _onclick;
	public:
		DialogButton(char key, string action, function<void()> onclick) : _key(key), _action(action), _onclick(onclick) {}
		void update(char ch, bool& ok) {
			if (ch == _key) {
				ok = false;
				_onclick();
			}
		}
		char get_key() {return _key;}
		string get_action() {return _action;}
	};

	class Dialog {
	private:
		string _text;
		vector<DialogButton*> _buttons;
	public:
		Dialog(string text) : _text(text) {}
		void add_button(DialogButton* button) {
			_buttons.push_back(button);
		}
		void start() {
			bool ok = true;
			while(ok) {
				clear();
				mvwprintw(stdscr, 1, 1, "%s", _text.c_str());
				int i = 3;
				for_each(_buttons.begin(), _buttons.end(), [&i](DialogButton* button){mvwprintw(stdscr, i, 1, "%c - %s", button->get_key(), button->get_action().c_str()); i++;});
				char ch = getch();
				for_each(_buttons.begin(), _buttons.end(), [ch, &ok](DialogButton* button){button->update(ch, ok);});
				usleep(10000);
			}
		}
	};
}
