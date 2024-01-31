#pragma once

#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

using namespace std;

namespace Gald {
class SoundPlayer {
	string _path;
	bool _is_playing;
	sf::Sound* _sound;
	sf::SoundBuffer* _buffer;

public:
	SoundPlayer(string path) {
		_path = path;
		_is_playing = false;
		_buffer = new sf::SoundBuffer;
		_buffer->loadFromFile(path.c_str());
		_sound = new sf::Sound(*_buffer);
	}
	void play() {
		bool is_playing = true;
		_sound->play();
	}
	bool is_playing() {
		return (_sound->getStatus() == _sound->Playing ? 1 : 0);
	}
	void stop() {
		bool is_playing = false;
		_sound->stop();
	}
	~SoundPlayer() {
		delete _sound;
		delete _buffer;
	}
};
}
