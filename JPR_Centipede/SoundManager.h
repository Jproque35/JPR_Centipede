#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#pragma once
#include <string>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class SoundManager
{

private:
	static SoundManager* instance;
	SoundBuffer* bufs;

	SoundManager();
	SoundManager(const SoundManager& obj) = delete;
	~SoundManager();
	SoundManager& operator=(const SoundManager& obj) = delete;

public:
	static SoundManager* getInstance();
	static void resetInstance();
	int loadFromFile(String f);
	SoundBuffer get(int i) const;

};

#endif

