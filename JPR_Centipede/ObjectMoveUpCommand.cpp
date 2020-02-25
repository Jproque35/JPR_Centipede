#include "ObjectMoveUpCommand.h"

ObjectMoveUpCommand::ObjectMoveUpCommand(GameObject* context) {

	this->init(context);

}

void ObjectMoveUpCommand::init(GameObject* context) {

	this->context = context;
	this->yDest = this->context->position.y - 1.0f;

}

void ObjectMoveUpCommand::reset(GameObject* context) {

	this->init(context);

}

void ObjectMoveUpCommand::execute(float elapsedTime) {

	float moveDist = this->context->ySpeed * elapsedTime;

	if (this->context->position.y - moveDist <= this->yDest) {

		this->context->position.y = this->yDest;
		this->finished = true;

	}
	else {

		this->context->position.y -= moveDist;

	}

}