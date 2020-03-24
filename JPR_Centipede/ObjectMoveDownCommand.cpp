#include "ObjectMoveDownCommand.h"
#include "GameObject.h"

ObjectMoveDownCommand::ObjectMoveDownCommand(GameObject* context) {

	this->context = context;
	this->yDest = this->context->getY() + 1.0f;
	this->type = CommandType::MoveDown;

}

ObjectMoveDownCommand::ObjectMoveDownCommand(const ObjectMoveDownCommand& obj) {

	this->context = obj.context;
	this->yDest = obj.yDest;
	this->finished = obj.finished;
	this->type = obj.type;

}

ObjectMoveDownCommand::~ObjectMoveDownCommand() {

	//cout << "Deleting MoveDownCommand..." << endl;

}

ObjectMoveDownCommand& ObjectMoveDownCommand::operator=(const ObjectMoveDownCommand& obj) {

	return *this;

}

ObjectCommand* ObjectMoveDownCommand::recontextCopy(GameObject* obj) {

	return new ObjectMoveDownCommand(obj);

}

void ObjectMoveDownCommand::execute(float elapsedTime) {

	
	float moveDist = this->context->getYSpeed() * elapsedTime;

	if (this->context->getY() + moveDist >= this->yDest) {

		this->context->setY(yDest);
		this->finished = true;

	}
	else {

		this->context->setY(this->context->getY() + moveDist);

	}

	this->context->setSpritePosition( this->context->getX(), this->context->getY() );
	this->context->setShapePosition( this->context->getX(), this->context->getY() );
	
	/*
	float moveDist = this->context->getYSpeed() * elapsedTime;
	this->context->setY(this->context->getY() + moveDist);

	this->context->setSpritePosition(this->context->getX(), this->context->getY());
	this->context->setShapePosition(this->context->getX(), this->context->getY());

	this->finished = true;*/

}