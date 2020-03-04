#include "Mushroom.h"

Mushroom::Mushroom(float initX, float initY) {

	this->context = new MushroomData(initX, initY);
	this->state = new GenericState();

}

Mushroom::Mushroom(const Mushroom& obj) {

	this->context = obj.context;

}

Mushroom::~Mushroom() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

Mushroom& Mushroom::operator=(const Mushroom& obj) {

	return *this;

}

ObjectData* Mushroom::getData() {

	return this->context;

}

void Mushroom::preUpdate(float elapsedTime) {



}
void Mushroom::postUpdate(float elapsedTime) {



}