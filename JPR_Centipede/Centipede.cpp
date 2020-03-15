#include "Centipede.h"
#include "CentipedeHeadState.h"

Centipede::Centipede(float initX, float initY) {

	this->context = new CentipedeData(initX, initY);
	this->state = new GenericState();
	this->type = CentipedeType::Head;
	this->init(initX, initY);
	//this->state = new CentipedeHeadState(this->context);

}

Centipede::Centipede(const Centipede& obj) {

	this->context = obj.context;
	this->type = obj.type;

}

Centipede::~Centipede() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

Centipede& Centipede::operator=(const Centipede& obj) {

	return *this;

}

void Centipede::init(float xPos, float yPos) {

	this->context->init(xPos, yPos);

}

ObjectData* Centipede::getData() const {

	return this->context;

}

CentipedeType Centipede::getCentipedeType() const {

	return this->type;

}

void Centipede::setCentipedeType(CentipedeType type) {

	this->type = type;

}

void Centipede::preUpdate(float elapsedTime) {


}

void Centipede::postUpdate(float elapsedTime) {


}