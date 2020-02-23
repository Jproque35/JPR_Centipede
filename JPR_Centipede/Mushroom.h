#ifndef MUSHROOM_H
#define MUSHROOM_H
#pragma once
#include "GameObject.h"

using namespace sf;

class Mushroom :
	public GameObject
{
	friend class MushroomController;

private:
	int health = 4.0f;
	bool inHitStun = false;

public:
	Mushroom(float initX, float initY);

};

#endif

