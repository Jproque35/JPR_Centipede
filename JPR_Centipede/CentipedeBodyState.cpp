#include "CentipedeBodyState.h"

CentipedeBodyState::CentipedeBodyState(CentipedeData* data) {

	this->context = data;

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

			if (this->context->getNext() != NULL) {

				//cout << "Command sent to " << this->context->getNext() << endl;
				//this->context->getNext()->queueCommand(CommandFactory::makeCommand(currCommand->getType(), (ObjectData*)(this->context->getNext())));

			}

			this->commands.pop();
			delete(currCommand);
			currCommand = NULL;

		}

	}

}