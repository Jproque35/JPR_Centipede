#include "ObjectMoveDownCommand.h"

ObjectMoveDownCommand::ObjectMoveDownCommand(GameObject* context) {

	this->context = context;
	this->yDest = this->context->position.y + 1.0f;
	this->type = CommandType::MoveDown;

}

ObjectMoveDownCommand::ObjectMoveDownCommand(const ObjectMoveDownCommand& obj) {

	this->context = obj.context;
	this->yDest = obj.yDest;
	this->finished = obj.finished;
	this->type = obj.type;

}

ObjectMoveDownCommand::~ObjectMoveDownCommand() {}

ObjectMoveDownCommand& ObjectMoveDownCommand::operator=(const ObjectMoveDownCommand& obj) {

	return *this;

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