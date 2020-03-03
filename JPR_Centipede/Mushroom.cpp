#include "Mushroom.h"

Mushroom::Mushroom(float initX, float initY) {

	this->context = new MushroomData(initX, initY);

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

void Mushroom::updateSub(float elapsedTime) {



}

ObjectData* Mushroom::getData() {

	return this->context;

}