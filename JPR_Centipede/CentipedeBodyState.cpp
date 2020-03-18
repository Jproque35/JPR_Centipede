#include "CentipedeBodyState.h"

CentipedeBodyState::CentipedeBodyState(CentipedeData* data) {

	this->context = data;
	this->lastPos = data->getPosition();

}

void CentipedeBodyState::executeEventListeners(float elapsedTime) {

	for (int i = 0; i < events.size(); i++) {

		this->events[i]->update(elapsedTime);

	}

}

void CentipedeBodyState::executeCommand(float elapsedTime) {

	if (commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();

		currCommand->execute(elapsedTime);

		if (currCommand->isFinished()) {

			//cout << this->context->getNext() << endl;

			GameObjectManager* gm = GameObjectManager::getInstance();

			if (this->context->getNextId() > -1) {

				Centipede* nextObj = (Centipede*)(gm->get(this->context->getNextId()));
				nextObj->getData()->setPosition(this->lastPos);
				nextObj->queueCommand(CommandFactory::makeCommand(currCommand->getType(), nextObj->getData()));

			}

			this->commands.pop();
			delete(currCommand);
			currCommand = NULL;
			this->lastPos = this->context->getPosition();

		}

	}

}