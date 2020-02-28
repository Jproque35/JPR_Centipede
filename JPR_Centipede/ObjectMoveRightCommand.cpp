#include "ObjectMoveRightCommand.h"

ObjectMoveRightCommand::ObjectMoveRightCommand(GameObject* context) {

	this->init(context);

}

void ObjectMoveRightCommand::init(GameObject* context) {

	this->context = context;
	this->xDest = this->context->position.x + 1.0f;

}

void ObjectMoveRightCommand::reset(GameObject* context) {

	this->init(context);

}

void ObjectMoveRightCommand::execute(float elapsedTime) {

	float moveDist = this->context->xSpeed * elapsedTime;

	if (this->context->position.x + moveDist >= this->xDest) {

		this->context->position.x = this->xDest;

		if (this->context->type == ObjectType::Player) {

			cout << "Final position is " << this->context->position.x << ", " << this->context->position.y << endl;

		}

		this->finished = true;

	}
	else {

		this->context->position.x += moveDist;

	}

	this->context->shape.setPosition(this->context->position);

}