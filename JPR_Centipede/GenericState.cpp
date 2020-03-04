#include "GenericState.h"

void GenericState::executeEventListeners(vector<GameEventListener*>& events, float elapsedTime) {

	for (int i = 0; i < events.size(); i++) {

		events[i]->update(elapsedTime);

	}

}

void GenericState::executeCommand(queue<ObjectCommand*>& commands, float elapsedTime) {

	if (commands.size() > 0) {

		ObjectCommand* currCommand = commands.front();

		currCommand->execute(elapsedTime);

		if (currCommand->isFinished()) {

			commands.pop();
			delete(currCommand);
			currCommand = NULL;

		}

	}

}