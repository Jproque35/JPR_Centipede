#include "ObjectController.h"

ObjectController::~ObjectController() {

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

			this->commands.pop();
			delete(currCommand);

		}

	}

}

void ObjectController::update(float elapsedTime) {

	this->updateSub(elapsedTime);
	this->executeCommand(elapsedTime);

}