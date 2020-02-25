#include "ObjectMoveLeftCommand.h"

ObjectMoveLeftCommand::ObjectMoveLeftCommand(GameObject* context) {

	this->init(context);

}

void ObjectMoveLeftCommand::init(GameObject* context) {

	this->context = context;
	this->xDest = this->context->position.x - 1.0f;

}

void ObjectMoveLeftCommand::reset(GameObject* context) {

	this->init(context);

}

void ObjectMoveLeftCommand::execute(float elapsedTime) {

	float moveDist = this->context->xSpeed * elapsedTime;

	if (this->context->position.x - moveDist <= this->xDest) {

		this->context->position.x = this->xDest;
		this->finished = true;

	}
	else {

		this->context->position.x -= moveDist;

	}

}