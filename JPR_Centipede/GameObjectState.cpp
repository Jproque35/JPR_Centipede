#include "GameObjectState.h"
#include "ObjectCommand.h"
#include "GameEvent.h"

GameObjectState::~GameObjectState() {

	cout << "Destroying GameObjectState..." << endl;

	for (int i = 0; i < this->events.size(); i++) {

		if (this->events[i] != NULL) {

			delete(this->events[i]);
			this->events[i] = NULL;

		}

	}

	ObjectCommand* currCommand = NULL;
	while (this->commands.size() > 0) {

		currCommand = this->commands.front();

		if (currCommand != NULL) {
			delete(currCommand);
		}

		this->commands.pop();
		currCommand = NULL;

	}


}

StateType GameObjectState::getType() const {

	return this->type;

}

int GameObjectState::getNumCommands() const {

	return this->commands.size();

}

void GameObjectState::queueCommand(ObjectCommand* command) {

	this->commands.push(command);

}

void GameObjectState::setCommandType(CommandType type) {

	if (this->cmdTbl.count(type) > 0) {

		this->currCommand = this->cmdTbl[type];

	}
	else if (type == CommandType::Empty) {

		this->currCommand = NULL;

	}

}

void GameObjectState::addEventListener(GameEventListener* event) {

	this->events.push_back(event);

}

void GameObjectState::clearCommands() {

	while (this->commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();
		this->commands.pop();
		delete(currCommand);
		currCommand = NULL;

	}
}

void GameObjectState::clearEventListeners() {

	while (this->events.size() > 0) {

		GameEventListener* currEvent = this->events.front();
		if (currEvent != NULL) {

			delete(currEvent);
			currEvent = NULL;

		}
		this->commands.pop();

	}
}