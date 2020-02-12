#pragma once
#include "MovingObject.h"

class MovingObjectState {

protected:
	MovingObject* obj;

public:
	MovingObjectState(MovingObject* obj);
	virtual void checkCollision(GameObject* objs[]) = 0;
	virtual void checkCollision(GameObject* obj) = 0;
	virtual void checkCollision(Window* w) = 0;
	virtual void update(float elapsedTime) = 0;


};