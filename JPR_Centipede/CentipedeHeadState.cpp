#include "CentipedeHeadState.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ObjectCommand.h"
#include "GameEvent.h"
#include "CentipedeMoveEvent.h"
#include "CommandFactory.h"
#include "CentipedeHitEvent.h"

CentipedeHeadState::CentipedeHeadState(Centipede* data) {

	this->context = data;
	this->lastPos = data->getPosition();
	this->type = StateType::CentipedeHeadState;

	this->events.push_back( new CentipedeMoveEvent(data) );
	this->events.push_back(new CentipedeHitEvent(data));

}

void CentipedeHeadState::executeEventListeners(float elapsedTime) {

	for (int i = 0; i < events.size(); i++) {

		this->events[i]->update(elapsedTime);

	}

}

void CentipedeHeadState::executeCommand(float elapsedTime) {

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

void CentipedeHeadState::update(float elapsedTime) {

	this->executeCommand(elapsedTime);

}