#include "ObjectMoveUpCommand.h"
#include "GameObject.h"

ObjectMoveUpCommand::ObjectMoveUpCommand(GameObject* context) {

	this->context = context;
	this->yDest = this->context->getY() - 1.0f;
	this->type = CommandType::MoveUp;

}

ObjectMoveUpCommand::ObjectMoveUpCommand(const ObjectMoveUpCommand& obj) {

	this->context = obj.context;
	this->yDest = obj.yDest;
	this->finished = obj.finished;

}

ObjectMoveUpCommand::~ObjectMoveUpCommand() {

	//cout << "Deleting MoveUpCommand..." << endl;

}

ObjectMoveUpCommand& ObjectMoveUpCommand::operator=(const ObjectMoveUpCommand& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

ObjectCommand* ObjectMoveUpCommand::recontextCopy(GameObject* obj) {

	return new ObjectMoveUpCommand(obj);

}

void ObjectMoveUpCommand::execute(float elapsedTime) {

	
	float moveDist = this->context->getYSpeed() * elapsedTime;

	if (this->context->getY() - moveDist <= this->yDest) {

		this->context->setY( this->yDest );
		this->finished = true;

	}
	else {

		this->context->setY( this->context->getY() - moveDist );

	}

	this->context->setShapePosition(this->context->getX(), this->context->getY());
	this->context->setSpritePosition(this->context->getX(), this->context->getY());
		/*
	float moveDist = this->context->getYSpeed() * elapsedTime;
	this->context->setY(this->context->getY() - moveDist);

	this->context->setShapePosition(this->context->getX(), this->context->getY());
	this->context->setSpritePosition(this->context->getX(), this->context->getY());

	this->finished = true;*/

}