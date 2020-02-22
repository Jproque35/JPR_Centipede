#include "ObjectController.h"

ObjectController::~ObjectController() {

	while (this->commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();
		this->commands.pop();
		delete(currCommand);
		currCommand = NULL;

	}

}

void ObjectController::checkCollisionWithObjects(vector<vector<GameObject*>> objs) {

	for (int i = 0; i < objs.size(); i++) {

		vector<GameObject*> currList = objs[i];

		for (int j = 0; j < currList.size(); j++) {

			GameObject* currObject = currList[j];

			this->collisionSub(currObject);

		}

	}

}

void ObjectController::executeCommand(float elapsedTime) {

	if (this->commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();

		currCommand->execute(elapsedTime);

		if (currCommand->isFinished()) {

			this->commands.pop();
			delete(currCommand);
			currCommand = NULL;

		}

	}

}

void ObjectController::update(float elapsedTime) {

	this->updateSub(elapsedTime);
	this->executeCommand(elapsedTime);

}