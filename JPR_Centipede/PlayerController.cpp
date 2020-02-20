#include "PlayerController.h"

PlayerController::PlayerController(Player* context) {

	this->context = context;

}

void PlayerController::setKey(Keyboard::Key key) {

	this->key = key;

}

void PlayerController::update(float elapsedTime) {

	if (this->context->getCommandQueueSize() < 1) {
		if (key == Keyboard::W) {

			this->context->queueCommand(new ObjectMoveUpCommand(this->context));

		}
		else if (key == Keyboard::A) {

			this->context->queueCommand(new ObjectMoveLeftCommand(this->context));

		}
		else if (key == Keyboard::D) {

			this->context->queueCommand(new ObjectMoveRightCommand(this->context));

		}
		else if (key == Keyboard::S) {

			this->context->queueCommand(new ObjectMoveDownCommand(this->context));

		}

		key = Keyboard::Unknown;

	}

	this->context->update(elapsedTime);

}