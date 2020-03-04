#include "GenericState.h"

GenericState::GenericState() {

	this->type = StateType::Generic;

}

GenericState::GenericState(const GenericState& obj) {

	this->type = obj.type;

}

GenericState::~GenericState() {



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

		ObjectCommand* currCommand = this->commands.front();

		currCommand->execute(elapsedTime);

		if (currCommand->isFinished()) {

			this->commands.pop();
			delete(currCommand);
			currCommand = NULL;

		}

	}

}