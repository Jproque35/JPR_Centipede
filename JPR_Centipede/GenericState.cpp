#include "GenericState.h"
#include "GameEvent.h"
#include "ObjectCommand.h"

GenericState::GenericState() {

	this->type = StateType::GenericState;

}

GenericState::~GenericState() {

	//cout << "Deleting GenericState..." << endl;

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
/*
void GenericState::update(float elapsedTime) {

	this->executeCommand(elapsedTime);

}*/