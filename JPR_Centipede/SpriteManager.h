#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H
#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class SpriteManager
{

private:
	static SpriteManager* instance;

	SpriteManager();
	SpriteManager(const SpriteManager& obj) = delete;
	~SpriteManager();
	SpriteManager& operator=(const SpriteManager& obj) = delete;

public:
	static SpriteManager* getInstance();
	static void resetInstance();
	int loadFromFile(String f);
};

#endif

