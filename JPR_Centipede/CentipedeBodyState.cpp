#include "CentipedeBodyState.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ObjectCommand.h"
#include "GameEvent.h"
#include "CommandFactory.h"
#include "CentipedeBodyHitEvent.h"

CentipedeBodyState::CentipedeBodyState(Centipede* data) {

	this->context = data;
	this->lastPos = data->getPosition();
	this->events.push_back(new CentipedeBodyHitEvent(data));

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

			if (this->context->getNext() != NULL) {

				this->context->getNext()->setX(this->lastPos.x);
				this->context->getNext()->setY(this->lastPos.y);
				this->context->getNext()->getState()->queueCommand(
					CommandFactory::makeCommand(currCommand->getType(), this->context->getNext()));

			}

			this->commands.pop();
			delete(currCommand);
			currCommand = NULL;
			this->lastPos = this->context->getPosition();

		}

	}

}

void CentipedeBodyState::update(float elapsedTime) {

	this->executeCommand(elapsedTime);

}