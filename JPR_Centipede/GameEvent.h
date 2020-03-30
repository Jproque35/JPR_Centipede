#ifndef GAMEEVENTLISTENER_H
#define GAMEEVENTLISTENER_H
#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameObject;

class GameEventListener
{

public:
	virtual ~GameEventListener();
	virtual GameEventListener* recontextCopy(GameObject* obj) = 0;
	virtual void update(float elapsedTime) = 0;

};
#endif

