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

	SoundManager();
	SoundManager(const SoundManager& obj);
	~SoundManager();
	SoundManager& operator=(const SoundManager& obj);

public:
	static SoundManager* getInstance();
	static void resetInstance();
	int loadFromFile(String f);

};

#endif

