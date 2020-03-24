#include "GenericState.h"
#include "GameEvent.h"
#include "ObjectCommand.h"

GenericState::GenericState() {

	this->type = StateType::GenericState;

}

GenericState::GenericState(const GenericState& obj) {

	this->type = obj.type;

}

GenericState::~GenericState() {

	cout << "Deleting GenericState..." << endl;

}

GenericState& GenericState::operator=(const GenericState& obj) {

	return *this;

}

void GenericState::executeEventListeners(float elapsedTime) {

	for (int i = 0; i < events.size(); i++) {

		this->events[i]->update(elapsedTime);

	}

}

void GenericState::executeCommand(float elapsedTime) {

	if (commands.size() > 0) {

		ObjectCommand* currComm = this->commands.front();

		currComm->execute(elapsedTime);

		if (currComm->isFinished()) {

			this->commands.pop();
			delete(currComm);
			currComm = NULL;

		}

	}

}

void GenericState::update(float elapsedTime) {

	this->executeCommand(elapsedTime);
	
	/*
	if (this->currCommand != NULL) {

		this->currCommand->execute(elapsedTime);

	}*/

}