#include "CentipedeController.h"

CentipedeController::CentipedeController(Centipede* context) {

	this->context = context;

}

void CentipedeController::checkCollision(GameObject* obj, float elapsedTime) {

	FloatRect colBox1 = this->context->getCollisionBox();
	FloatRect colBox2 = obj->getCollisionBox();

}

void CentipedeController::checkCollision(float xBoundary, float yBoundary, float elapsedTime) {

	Vector2f currPos = this->context->position;
	float xDist = this->context->xSpeed * elapsedTime;
	float yDist = this->context->ySpeed * elapsedTime;

	if (this->dir == CentipedeDirection::Left || this->dir == CentipedeDirection::Right) {

		if (currPos.x - xDist <= 0 && !this->changingLevels) {

			this->changeLevelRight();

		}
		else if (currPos.x + this->context->getShape().getRadius() * 2 + xDist >= floor(xBoundary) - 1.0f && !this->changingLevels) {

			this->changeLevelLeft();

		}

	}

	if (this->context->position.y - yDist <= 0.0f) {

		this->inReverse = false;

	}
	else if (this->context->position.y + yDist >= floor(yBoundary) - 1.0f) {

		this->inReverse = true;

	}

}

void CentipedeController::changeLevelLeft() {

	this->dir = CentipedeDirection::Left;
	this->queueLevelChangeCommand();
	this->context->queueCommand(new ObjectMoveLeftCommand(this->context));
	this->changingLevels = true;

}

void CentipedeController::changeLevelRight() {

	this->dir = CentipedeDirection::Right;
	this->queueLevelChangeCommand();
	this->context->queueCommand(new ObjectMoveRightCommand(this->context));
	this->changingLevels = true;

}

void CentipedeController::queueLevelChangeCommand() {

	if (!this->inReverse) {
		this->context->queueCommand(new ObjectMoveDownCommand(this->context));
	}
	else {
		this->context->queueCommand(new ObjectMoveUpCommand(this->context));
	}

}

void CentipedeController::update(float elapsedTime) {

	if (this->context->getCommandQueueSize() < 1) {

		if (this->dir == CentipedeDirection::Left) {
			this->context->queueCommand(new ObjectMoveLeftCommand(this->context));
		}
		else if (this->dir == CentipedeDirection::Right) {
			this->context->queueCommand(new ObjectMoveRightCommand(this->context));
		}

		this->changingLevels = false;

	}

	this->context->update(elapsedTime);

}