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
/*
void GenericState::update(float elapsedTime) {

	this->executeCommand(elapsedTime);

}*/