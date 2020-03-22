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

		ObjectCommand* currCommand = this->commands.front();

		currCommand->execute(elapsedTime);

		if (currCommand->isFinished()) {

			this->commands.pop();
			delete(currCommand);
			currCommand = NULL;

		}

	}

}

void GenericState::update(float elapsedTime) {

	this->executeCommand(elapsedTime);

}