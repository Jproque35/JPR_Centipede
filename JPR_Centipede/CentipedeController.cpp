#include "CentipedeController.h"

CentipedeController::CentipedeController(Centipede* context) {

	this->context = context;

}

GameObject* CentipedeController::getData() {

	return this->context;

}

void CentipedeController::checkCollision(float xBoundary, float yBoundary, float elapsedTime) {

	Vector2f currPos = this->context->position;
	float xDist = this->context->xSpeed * elapsedTime;
	float yDist = this->context->ySpeed * elapsedTime;

	if (this->dir == CentipedeDirection::Left || this->dir == CentipedeDirection::Right) {

		if (currPos.x - xDist <= 0 && !this->changingLevels) {

			this->changeLevelRight();

		}
		else if (currPos.x + this->context->getShape().getRadius() * 2 + xDist >= xBoundary - 1.0f && !this->changingLevels) {

			this->changeLevelLeft();

		}

	}

	if (this->context->position.y - yDist <= 0.0f) {

		this->inReverse = false;

	}
	else if (this->context->position.y + yDist >= yBoundary - 1.0f) {

		this->inReverse = true;

	}

}

void CentipedeController::changeLevelLeft() {

	this->dir = CentipedeDirection::Left;
	this->queueLevelChangeCommand();
	this->commands.push(new ObjectMoveLeftCommand(this->context));
	this->changingLevels = true;

}

void CentipedeController::changeLevelRight() {

	this->dir = CentipedeDirection::Right;
	this->queueLevelChangeCommand();
	this->commands.push(new ObjectMoveRightCommand(this->context));
	this->changingLevels = true;

}

void CentipedeController::queueLevelChangeCommand() {

	if (!this->inReverse) {
		this->commands.push(new ObjectMoveDownCommand(this->context));
	}
	else {
		this->commands.push(new ObjectMoveUpCommand(this->context));
	}

}

void CentipedeController::updateSub(float elapsedTime) {

	if (this->commands.size() < 1) {

		if (this->dir == CentipedeDirection::Left) {
			this->commands.push(new ObjectMoveLeftCommand(this->context));
		}
		else if (this->dir == CentipedeDirection::Right) {
			this->commands.push(new ObjectMoveRightCommand(this->context));
		}

		this->changingLevels = false;

	}

}

void CentipedeController::collisionSub(GameObject* obj) {

	if (this->context != obj) {

		float diameter0 = this->context->getShape().getRadius() * 2;
		float diameter1 = obj->getShape().getRadius() * 2;

		if (this->context->getPosition().y + diameter0 >= obj->getPosition().y ||
			this->context->getPosition().y <= obj->getPosition().y + diameter1) {

			if (this->context->getPosition().x + diameter0 >= obj->getPosition().x ||
				this->context->getPosition().x <= obj->getPosition().x + diameter1) {

				cout << "Intersection detected with object " << obj << endl;
				if (obj->getType() == ObjectType::PlayerProjectile && obj->isActive()) {

					cout << "Hit detected" << endl;

				}

			}

		}

	}

}