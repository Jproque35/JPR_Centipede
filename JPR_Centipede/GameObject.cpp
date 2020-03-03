#include "GameObject.h"

int GameObject::commandQueueSize() {

	return this->commands.size();

}

void GameObject::addEventListener(GameEventListener* event) {

	this->events.push_back(event);

}

void GameObject::executeEventListeners(float elapsedTime) {

	for (int i = 0; i < this->events.size(); i++) {

		this->events[i]->update(elapsedTime);

	}

}

void GameObject::clearEventListeners() {

	while (this->events.size() > 0) {

		GameEventListener* currEvent = this->events.front();
		if (currEvent != NULL) {

			delete(currEvent);
			currEvent = NULL;

		}
		this->commands.pop();

	}

}

void GameObject::queueCommand(ObjectCommand* command) {

	this->commands.push(command);

}

void GameObject::clearCommands() {

	while (this->commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();
		this->commands.pop();
		delete(currCommand);
		currCommand = NULL;

	}

}

void GameObject::executeCommand(float elapsedTime) {

	if (this->commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();

		currCommand->execute(elapsedTime);

		if (currCommand->isFinished()) {

			//this->handleFinishedCommand(currCommand);

			if (currCommand != NULL) {

				this->commands.pop();
				delete(currCommand);
				currCommand = NULL;

			}

		}

	}

}

void GameObject::update(float elapsedTime) {

	this->updateSub(elapsedTime);
	this->executeCommand(elapsedTime);

}