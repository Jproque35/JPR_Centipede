#include "ObjectMoveUpCommand.h"

ObjectMoveUpCommand::ObjectMoveUpCommand(ObjectData* context) {

	this->context = context;
	this->yDest = this->context->position.y - 1.0f;
	this->type = CommandType::MoveUp;

}

ObjectMoveUpCommand::ObjectMoveUpCommand(const ObjectMoveUpCommand& obj) {

	this->context = obj.context;
	this->yDest = obj.yDest;
	this->finished = obj.finished;

}

ObjectMoveUpCommand::~ObjectMoveUpCommand() {}

ObjectMoveUpCommand& ObjectMoveUpCommand::operator=(const ObjectMoveUpCommand& obj) {

	return *this;

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

	this->context->shape.setPosition(this->context->position);
	this->context->spr.setPosition(this->context->position);

}