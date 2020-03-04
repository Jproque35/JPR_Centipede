#include "GameObject.h"

int GameObject::commandQueueSize() {

	return this->commands.size();

}

void GameObject::addEventListener(GameEventListener* event) {

	this->events.push_back(event);

}

void GameObject::executeEventListeners(float elapsedTime) {

	this->state->executeEventListeners(this->events, elapsedTime);

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

int GameObject::commandsSize() {

	return this->commands.size();

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

	this->state->executeCommand(this->commands, elapsedTime);

}

void GameObject::update(float elapsedTime) {

	this->preUpdate(elapsedTime);
	this->executeCommand(elapsedTime);
	this->postUpdate(elapsedTime);

}