#include "MovingObject.h"


MovingObject::MovingObject(float initX, float initY) :GameObject(initX, initY) {

	this->xSpeed = 400.0f;
	this->ySpeed = 400.0f;
	this->shape.setSize(Vector2f(50.0f, 50.0f));
	this->type = ObjectType::MovingObject;
	this->currState = MovingObjectState::MoveLeft;
	this->lastSideState = MovingObjectState::MoveRight;
	this->inReverse = false;

}

