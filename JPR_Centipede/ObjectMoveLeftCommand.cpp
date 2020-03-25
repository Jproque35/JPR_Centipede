#include "ObjectMoveLeftCommand.h"
#include "GameObject.h"

ObjectMoveLeftCommand::ObjectMoveLeftCommand(GameObject* context) {

	this->context = context;
	this->xDest = this->context->getX() - 1.0f;
	this->type = CommandType::MoveLeft;

}

ObjectMoveLeftCommand::ObjectMoveLeftCommand(const ObjectMoveLeftCommand& obj) {

	this->context = obj.context;
	this->xDest = obj.xDest;
	this->finished = obj.finished;
	this->type = obj.type;

}

ObjectMoveLeftCommand::~ObjectMoveLeftCommand() {

	//cout << "Deleting MoveLeftCommand..." << endl;

}

ObjectMoveLeftCommand& ObjectMoveLeftCommand::operator=(const ObjectMoveLeftCommand& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

ObjectCommand* ObjectMoveLeftCommand::recontextCopy(GameObject* obj) {

	return new ObjectMoveLeftCommand(obj);

}

void ObjectMoveLeftCommand::execute(float elapsedTime) {

	
	float moveDist = this->context->getXSpeed() * elapsedTime;

	if (this->context->getX() - moveDist <= this->xDest) {

		this->context->setX(this->xDest);
		this->finished = true;

	}
	else {

		this->context->setX(this->context->getX() - moveDist);

	}

	this->context->setShapePosition(this->context->getX(), this->context->getY());
	this->context->setSpritePosition(this->context->getX(), this->context->getY());
		/*
	float moveDist = this->context->getXSpeed() * elapsedTime;
	this->context->setX(this->context->getX() - moveDist);

	this->context->setShapePosition(this->context->getX(), this->context->getY());
	this->context->setSpritePosition(this->context->getX(), this->context->getY());

	this->finished = true;*/

}