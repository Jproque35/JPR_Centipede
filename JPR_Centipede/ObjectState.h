#ifndef OBJECTSTATE_H
#define OBJECTSTATE_H
#pragma once
#include "GameObject.h"

using namespace sf;

class ObjectState
{

public:
	virtual void checkCollision(GameObject* obj) = 0;
	virtual void checkCollision(Window* w) = 0;
	virtual void update(float elapsedTime) = 0;

};

#endif

