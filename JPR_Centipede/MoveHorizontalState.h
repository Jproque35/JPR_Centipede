#pragma once
#include "MovingObjectState.h"
#include "MovingObject.h"

class MovingHorizontalState :
	public MovingObjectState
{

public:
	MovingHorizontalState(MovingObject* obj);
	void collideWithTopOrBottom();
	void collideWithLeftOrRight();
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);
};

