#ifndef MUSHROOMMANAGER_H
#define MUSHROOMMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma once

using namespace sf;
using namespace std;

class MushroomManager
{

private:
	static MushroomManager* instance;
	int numActive = 0;

	MushroomManager();
	~MushroomManager();
	MushroomManager(const MushroomManager& obj) = delete;
	MushroomManager& operator=(const MushroomManager& obj) = delete;

public:
	static MushroomManager* getInstance();
	static void resetInstance();

	void addMushroom(float xPos, float yPos);
	void removeMushroom(float xPos, float yPos);
	int getNumActive() const;

};

#endif
