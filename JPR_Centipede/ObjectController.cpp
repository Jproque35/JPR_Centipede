#include "ObjectController.h"

void ObjectController::clearCommands() {

	while (this->commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();
		this->commands.pop();
		delete(currCommand);
		currCommand = NULL;

	}

}

void ObjectController::queueCommand(ObjectCommand* command) {

	this->commands.push(command);

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