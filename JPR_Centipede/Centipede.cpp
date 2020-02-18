#include "Centipede.h"


Centipede::Centipede(float initX, float initY) :GameObject(initX, initY) {

	this->xSpeed = 15.0f;
	this->ySpeed = 15.0f;
	this->shape.setSize(Vector2f(1.0f, 1.0f));
	this->type = ObjectType::Centipede;
	this->currState = MovingObjectState::MoveLeft;
	this->lastSideState = MovingObjectState::MoveRight;

}

