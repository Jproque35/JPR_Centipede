#include "CentipedeController.h"

CentipedeController::CentipedeController(Centipede* context) {

	this->context = context;
	//this->grid = grid;
	this->head = true;

}

CentipedeController::CentipedeController(const CentipedeController& obj) {

	this->context = obj.context;
	this->commands = obj.commands;
	this->next = obj.next;
	this->head = obj.head;
	this->inReverse = obj.inReverse;

}

CentipedeController::~CentipedeController() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

CentipedeController& CentipedeController::operator=(const CentipedeController& obj) {

	return *this;

}

void CentipedeController::setNext(CentipedeController* next) {

	cout << "Next for object " << this << " set to " << next << endl;
	this->next = next;

}

GameObject* CentipedeController::getData() {

	return this->context;

}

void CentipedeController::updateSub(float elapsedTime) {


}