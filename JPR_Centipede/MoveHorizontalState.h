#pragma once
#include "MovingObjectState.h"

class MovingHorizontalState :
	public MovingObjectState
{

public:
	MovingHorizontalState(MovingObject* obj);
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);
};

