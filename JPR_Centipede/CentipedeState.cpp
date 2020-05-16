#include "CentipedeState.h"
#include "GameObjectManager.h"
#include "GameEvent.h"
#include "ObjectCommand.h"
#include "Centipede.h"
#include "CommandFactory.h"

CentipedeState::~CentipedeState() {

	//cout << "Destroying CentipedeState..." << endl;

}

void CentipedeState::init() {

	cout << "Centipede state virtual init" << endl;
	this->clearCommands();
	this->lastPos = Vector2f(-1.0f, -1.0f);

}

void CentipedeState::executeEventListeners(float elapsedTime) {

	for (int i = 0; i < events.size(); i++) {

		this->events[i]->update(elapsedTime);

	}

}

void CentipedeState::processNext(ObjectCommand* currCommand) {

	this->context->getNext()->setX(this->lastPos.x);
	this->context->getNext()->setY(this->lastPos.y);
	this->context->getNext()->setSpritePosition(this->context->getNext()->getX(),
		this->context->getNext()->getY());
	this->context->getNext()->getState()->queueCommand(
		CommandFactory::makeCommand(currCommand->getType(), this->context->getNext()));

}

void CentipedeState::executeCommand(float elapsedTime) {

	if (commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();

		currCommand->execute(elapsedTime);

		if (currCommand->isFinished()) {

			GameObjectManager* gm = GameObjectManager::getInstance();

			if (this->context->getNext() != NULL) {
				
				this->processNext(currCommand);

			}

			this->commands.pop();
			delete(currCommand);
			currCommand = NULL;
			this->lastPos = Vector2f(this->context->getX(), this->context->getY());

		}

	}

}