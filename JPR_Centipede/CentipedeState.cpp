#include "CentipedeState.h"
#include "GameObjectManager.h"
#include "GameEvent.h"
#include "ObjectCommand.h"
#include "Centipede.h"
#include "CommandFactory.h"

CentipedeState::CentipedeState(Centipede* obj) {

	this->context = obj;

}

CentipedeState::~CentipedeState() {

	//cout << "Destroying CentipedeState..." << endl;

}

void CentipedeState::init() {

	cout << "Centipede state virtual init" << endl;

}

void CentipedeState::executeEventListeners(float elapsedTime) {

	for (int i = 0; i < events.size(); i++) {

		this->events[i]->update(elapsedTime);

	}

}