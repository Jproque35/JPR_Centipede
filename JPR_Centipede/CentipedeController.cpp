#include "CentipedeController.h"

CentipedeController::CentipedeController(Centipede* context) {

	this->context = context;

}

void CentipedeController::checkCollision(float xBoundary, float yBoundary) {

	Vector2f currPos = this->context->getPosition();

	if (currPos.x <= 0 && !this->changingLevels) {

		cout << "Direction changed to right" << endl;
		this->dir = CentipedeDirection::Right;
		this->context->queueCommand(new CentipedeMoveDownCommand(this->context));
		this->context->queueCommand(new CentipedeMoveRightCommand(this->context));
		this->changingLevels = true;

	}
	else if (currPos.x + this->context->getShape().getRadius() * 2 >= floor(xBoundary) && !this->changingLevels) {

		cout << "Direction changed to left" << endl;
		this->dir = CentipedeDirection::Left;
		this->context->queueCommand(new CentipedeMoveDownCommand(this->context));
		this->context->queueCommand(new CentipedeMoveLeftCommand(this->context));
		this->changingLevels = true;

	}

}

void CentipedeController::update(float elapsedTime) {

	if (this->context->getCommandQueueSize() < 1) {

		if (this->dir == CentipedeDirection::Left) {
			this->context->queueCommand(new CentipedeMoveLeftCommand(this->context));
		}
		else if (this->dir == CentipedeDirection::Right) {
			this->context->queueCommand(new CentipedeMoveRightCommand(this->context));
		}

		this->changingLevels = false;

	}

	this->context->update(elapsedTime);

}