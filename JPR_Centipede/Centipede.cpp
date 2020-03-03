#include "Centipede.h"

Centipede::Centipede(float initX, float initY) {

	this->context = new CentipedeData(initX, initY);
	this->head = true;

}

Centipede::Centipede(const Centipede& obj) {

	this->context = obj.context;
	this->commands = obj.commands;
	this->next = obj.next;
	this->head = obj.head;
	this->inReverse = obj.inReverse;

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

void Centipede::setNext(Centipede* next) {

	cout << "Next for object " << this << " set to " << next << endl;
	this->next = next;

}

ObjectData* Centipede::getData() {

	return this->context;

}

void Centipede::updateSub(float elapsedTime) {


}