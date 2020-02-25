#include "CentipedeController.h"

CentipedeController::CentipedeController(Centipede* context) {

	this->context = context;
	//this->grid = grid;
	this->head = true;

}

void CentipedeController::setNext(CentipedeController* next) {

	cout << "Next for object " << this << " set to " << next << endl;
	this->next = next;

}

GameObject* CentipedeController::getData() {

	return this->context;

}

/*
void CentipedeController::collisionSub(GameObject* obj) {

	if (this->context != obj) {

		float diameter0 = this->context->getShape().getRadius() * 2;
		float diameter1 = obj->getShape().getRadius() * 2;

		if (this->context->getPosition().y + diameter0 >= obj->getPosition().y ||
			this->context->getPosition().y <= obj->getPosition().y + diameter1) {

			if (this->context->getPosition().x + diameter0 >= obj->getPosition().x ||
				this->context->getPosition().x <= obj->getPosition().x + diameter1) {


			}

		}

	}

}

void CentipedeController::handleFinishedCommand(ObjectCommand* command) {

	if (this->next == NULL) {

		delete(command);
		command = NULL;

	}
	else {

		this->next->queueCommand(command);

	}

}*/