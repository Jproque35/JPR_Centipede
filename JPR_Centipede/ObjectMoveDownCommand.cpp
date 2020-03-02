#include "ObjectMoveDownCommand.h"

ObjectMoveDownCommand::ObjectMoveDownCommand(GameObject* context) {

	this->init(context);

}

void ObjectMoveDownCommand::init(GameObject* context) {

	this->context = context;
	this->yDest = this->context->position.y + 1.0f;

}

ObjectMoveDownCommand::ObjectMoveDownCommand(const ObjectMoveDownCommand& obj) {

	this->context = obj.context;
	this->yDest = obj.yDest;
	this->finished = obj.finished;

}

ObjectMoveDownCommand::~ObjectMoveDownCommand() {}

ObjectMoveDownCommand& ObjectMoveDownCommand::operator=(const ObjectMoveDownCommand& obj) {

	return *this;

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