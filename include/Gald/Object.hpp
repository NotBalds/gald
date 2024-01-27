#pragma once

#include <bits/stdc++.h>
#include <ncurses.h>

using namespace std;

namespace Gald {
	class Object {
	friend class Window;
	
	protected:
		int _x, _y, _absolute_x, _absolute_y;
		string _name;
		map<string, Object*> _children;
		Object* _parent;
		virtual void _update() {
			update();
			for (auto i : _children) {
				i.second->_absolute_x = i.second->_x + this->_absolute_x;
				i.second->_absolute_y = i.second->_y + this->_absolute_y;
				i.second->_update();
			}
		}
	public:
		Object(int x, int y, string name) : _x(x), _y(y), _name(name), _absolute_x(x), _absolute_y(y) { 
			_parent = nullptr;
		}
		int add_child(Object* child) {
			if (child->_parent != nullptr) {
				return 1;
			}
			if (_children.find(child->_name) != _children.end()) {
				return -1;
			}

			child->_absolute_x = child->_x + this->_x;
			child->_absolute_y = child->_y + this->_y;
			child->_parent = this;
			_children[child->_name] = child;

			return 0;
		}
		void remove_child_by_name(string name) {
			Object* child = _children[name];
			child->_parent = nullptr;
			child->_absolute_x = child->_x;
			child->_absolute_y = child->_y;
			_children.erase(name);
		}
		Object* get_child_by_name(string name) {
			return _children[name];
		}
		Object* get_parent() {
			return _parent;
		}
		int get_x() {
			return _x;
		}
		int get_y() {
			return _y;
		}
		int get_absolute_x() {
			return _absolute_x;
		}
		int get_absolute_y() {
			return _absolute_y;
		}
		string get_name() {
			return _name;
		}
		void set_x(int x) {
			_x = x;
		}
		void set_y(int y) {
			_y = y;
		}
		virtual void update() {
			
		}
	};
}
