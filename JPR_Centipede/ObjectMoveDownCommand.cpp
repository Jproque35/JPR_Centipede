#include "ObjectMoveDownCommand.h"

ObjectMoveDownCommand::ObjectMoveDownCommand(GameObject* context) {

	this->init(context);

}

void ObjectMoveDownCommand::init(GameObject* context) {

	this->context = context;
	this->yDest = this->context->position.y + 1.0f;

}

void ObjectMoveDownCommand::reset(GameObject* context) {

	this->init(context);

}

void ObjectMoveDownCommand::execute(float elapsedTime) {

	float moveDist = this->context->ySpeed * elapsedTime;

	if (this->context->position.y + moveDist >= this->yDest) {

		this->context->position.y = yDest;
		this->finished = true;

	}
	else {

		this->context->position.y += moveDist;

	}

}