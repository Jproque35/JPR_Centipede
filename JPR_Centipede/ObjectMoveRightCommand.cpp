#include "ObjectMoveRightCommand.h"

ObjectMoveRightCommand::ObjectMoveRightCommand(ObjectData* context) {

	this->context = context;
	this->xDest = this->context->position.x + 1.0f;
	this->type = CommandType::MoveRight;

}

ObjectMoveRightCommand::ObjectMoveRightCommand(const ObjectMoveRightCommand& obj) {

	this->context = obj.context;
	this->xDest = obj.xDest;
	this->finished = obj.finished;
	this->type = obj.type;

}

ObjectMoveRightCommand::~ObjectMoveRightCommand() {}

ObjectMoveRightCommand& ObjectMoveRightCommand::operator=(const ObjectMoveRightCommand& obj) {

	return *this;

}

void ObjectMoveRightCommand::execute(float elapsedTime) {

	float moveDist = this->context->xSpeed * elapsedTime;

	if (this->context->position.x + moveDist >= this->xDest) {

		this->context->position.x = this->xDest;
		this->finished = true;

	}
	else {

		this->context->position.x += moveDist;

	}

	this->context->shape.setPosition(this->context->position);

}