#include "PlayerController.h"

PlayerController::PlayerController(float initX, float initY) {

	this->context = new Player(initX, initY);

}

PlayerController::PlayerController(const PlayerController& obj) {

	this->context = obj.context;
	this->commands = obj.commands;

}

PlayerController::~PlayerController() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

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

		this->key = Keyboard::Unknown;

	}

}

void PlayerController::collisionSub(GameObject* obj) {



}