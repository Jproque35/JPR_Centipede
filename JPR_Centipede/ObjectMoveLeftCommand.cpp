#include "ObjectMoveLeftCommand.h"

ObjectMoveLeftCommand::ObjectMoveLeftCommand(GameObject* context) {

	this->context = context;
	this->xDest = this->context->position.x - 1.0f;
	this->type = CommandType::MoveLeft;

}

ObjectMoveLeftCommand::ObjectMoveLeftCommand(const ObjectMoveLeftCommand& obj) {

	this->context = obj.context;
	this->xDest = obj.xDest;
	this->finished = obj.finished;
	this->type = obj.type;

}

ObjectMoveLeftCommand::~ObjectMoveLeftCommand() {}

ObjectMoveLeftCommand& ObjectMoveLeftCommand::operator=(const ObjectMoveLeftCommand& obj) {

	return *this;

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