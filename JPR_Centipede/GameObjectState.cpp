#include "GameObjectState.h"

StateType GameObjectState::getType() {

	return this->type;

}

int GameObjectState::getCommandQueueSize() {

	return this->commands.size();

}

void GameObjectState::queueCommand(ObjectCommand* command) {

	this->commands.push(command);

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