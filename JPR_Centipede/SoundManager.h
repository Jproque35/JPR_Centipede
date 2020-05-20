#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class SoundManager
{

private:
	static SoundManager* instance;
	vector<SoundBuffer*> bufs;

	SoundManager();
	SoundManager(const SoundManager& obj) = delete;
	~SoundManager();
	SoundManager& operator=(const SoundManager& obj) = delete;

	void parseLine(const char* str, int i);

public:
	static SoundManager* getInstance();
	static void resetInstance();
	void loadFromFile(const char* filename);
	SoundBuffer* get(int i) const;

};

#endif

