#include "GameObjectState.h"
#include "ObjectCommand.h"
#include "GameEvent.h"

GameObjectState::~GameObjectState() {

	//cout << "Destroying GameObjectState..." << endl;

	for (int i = 0; i < this->events.size(); i++) {

		if (this->events[i] != NULL) {

			delete(this->events[i]);
			this->events[i] = NULL;

		}

	}

}

void GameObjectState::init() {


	cout << "GameObjectState init" << endl;

}

StateType GameObjectState::getType() const {

	return this->type;

}

void GameObjectState::addEventListener(GameEventListener* event) {

	this->events.push_back(event);

}

void GameObjectState::clearEventListeners() {

	for (int i = 0; i < this->events.size(); i++) {

		if (this->events[i] != NULL) {

			delete(this->events[i]);
			this->events[i] = NULL;

		}

	}

}