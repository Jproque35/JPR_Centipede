#include "PlayerController.h"

PlayerController::PlayerController(Player* context) {

	this->context = context;

}

GameObject* PlayerController::getData() {

	return this->context;

}

void PlayerController::setKey(Keyboard::Key key) {

	this->key = key;

}

void PlayerController::updateSub(float elapsedTime) {

	if (this->commands.size() < 1) {
		if (key == Keyboard::W) {

			this->commands.push(new ObjectMoveUpCommand(this->context));

		}
		else if (key == Keyboard::A) {

			this->commands.push(new ObjectMoveLeftCommand(this->context));

		}
		else if (key == Keyboard::D) {

			this->commands.push(new ObjectMoveRightCommand(this->context));

		}
		else if (key == Keyboard::S) {

			this->commands.push(new ObjectMoveDownCommand(this->context));

		}

		key = Keyboard::Unknown;

	}

}

void PlayerController::collisionSub(GameObject* obj) {



}

/*
void PlayerController::handleFinishedCommand(ObjectCommand* command) {

	if (command != NULL) {

		delete(command);
		command = NULL;

	}

}*/