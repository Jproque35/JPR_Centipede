#include "ObjectMoveRightCommand.h"
#include "GameObject.h"

ObjectMoveRightCommand::ObjectMoveRightCommand(GameObject* context) {

	this->context = context;
	this->xDest = this->context->getX() + 1.0f;
	this->type = CommandType::MoveRight;

}

ObjectMoveRightCommand::ObjectMoveRightCommand(const ObjectMoveRightCommand& obj) {

	this->context = obj.context;
	this->xDest = obj.xDest;
	this->finished = obj.finished;
	this->type = obj.type;

}

ObjectMoveRightCommand::~ObjectMoveRightCommand() {

	cout << "Deleting MoveRightCommand..." << endl;

}

ObjectMoveRightCommand& ObjectMoveRightCommand::operator=(const ObjectMoveRightCommand& obj) {

	return *this;

}

void ObjectMoveRightCommand::execute(float elapsedTime) {

	float moveDist = this->context->getXSpeed() * elapsedTime;

	if (this->context->getX() + moveDist >= this->xDest) {

		this->context->setX(this->xDest);
		this->finished = true;

	}
	else {

		this->context->setX( this->context->getX() + moveDist );

	}

	this->context->setShapePosition(this->context->getX(), this->context->getY());
	this->context->setSpritePosition(this->context->getX(), this->context->getY());

}