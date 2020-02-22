#include "ObjectMoveRightCommand.h"

ObjectMoveRightCommand::ObjectMoveRightCommand(GameObject* context) {

	this->context = context;
	this->xDest = this->context->position.x + 1.0f;

}

void ObjectMoveRightCommand::execute(float elapsedTime) {

	float moveDist = this->context->xSpeed * elapsedTime;

	if (this->context->position.x + moveDist >= this->xDest) {

		this->context->position.x = this->xDest;
		this->finished = true;

	}
	else {

		this->context->position.x += moveDist;
		this->distTravelled += abs(moveDist);

	}

	this->context->shape.setPosition(this->context->position);

}