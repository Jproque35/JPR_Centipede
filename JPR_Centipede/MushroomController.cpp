#include "MushroomController.h"

MushroomController::MushroomController(Mushroom* context) {

	this->context = context;

}

MushroomController::MushroomController(const MushroomController& obj) {

	this->context = obj.context;

}

MushroomController::~MushroomController() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

MushroomController& MushroomController::operator=(const MushroomController& obj) {

	return *this;

}

void MushroomController::updateSub(float elapsedTime) {



}

GameObject* MushroomController::getData() {

	return this->context;

}