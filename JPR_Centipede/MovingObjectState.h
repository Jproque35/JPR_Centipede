#pragma once
#include "GameObject.h"
#include "MovingObject.h"

class MovingObjectState {

protected:
	MovingObject* obj;

public:
	MovingObjectState(MovingObject* obj);
	virtual void collideWithTopOrBottom() = 0;
	virtual void collideWithLeftOrRight() = 0;
	virtual void checkCollision(GameObject* objs[]) = 0;
	virtual void checkCollision(GameObject* obj) = 0;
	virtual void checkCollision(Window* w) = 0;
	virtual void update(float elapsedTime) = 0;


};