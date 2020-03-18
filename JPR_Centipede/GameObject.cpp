#include "GameObject.h"

void GameObject::setState(GameObjectState* state) {

	if (this->state != NULL) {

		delete(this->state);
		this->state = NULL;

	}

	this->state = state;

}

int GameObject::commandQueueSize() {

	return this->state->getCommandQueueSize();

}

void GameObject::addEventListener(GameEventListener* event) {

	this->state->addEventListener(event);

}

void GameObject::executeEventListeners(float elapsedTime) {

	this->state->executeEventListeners(elapsedTime);

}

void GameObject::clearEventListeners() {

	this->state->clearEventListeners();

}

int GameObject::commandsSize() {

	return this->state->getCommandQueueSize();

}

void GameObject::queueCommand(ObjectCommand* command) {

	this->state->queueCommand(command);

}

void GameObject::clearCommands() {

	this->state->clearCommands();

}

void GameObject::executeCommand(float elapsedTime) {

	this->state->executeCommand(elapsedTime);

}

void GameObject::update(float elapsedTime) {

	this->executeCommand(elapsedTime);

}