#include "ObjectController.h"

int ObjectController::commandQueueSize() {

	return this->commands.size();

}

void ObjectController::addEventListener(GameEventListener* event) {

	this->events.push_back(event);

}

void ObjectController::executeEventListeners(float elapsedTime) {

	for (int i = 0; i < this->events.size(); i++) {

		this->events[i]->update(elapsedTime);

	}

}

void ObjectController::clearEventListeners() {

	while (this->events.size() > 0) {

		GameEventListener* currEvent = this->events.front();
		if (currEvent != NULL) {

			delete(currEvent);
			currEvent = NULL;

		}
		this->commands.pop();

	}

}

void ObjectController::queueCommand(ObjectCommand* command) {

	this->commands.push(command);

}

void ObjectController::clearCommands() {

	while (this->commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();
		this->commands.pop();
		delete(currCommand);
		currCommand = NULL;

	}

}

void ObjectController::executeCommand(float elapsedTime) {

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

void ObjectController::update(float elapsedTime) {

	this->updateSub(elapsedTime);
	this->executeCommand(elapsedTime);

}