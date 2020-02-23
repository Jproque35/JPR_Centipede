#include "CentipedeController.h"



void CentipedeController::updateSub(float elapsedTime) {

	if (this->dir == CentipedeDirection::Left) {

		this->moveLeftRoutine();

	}
	else if (this->dir == CentipedeDirection::Right) {

		this->moveRightRoutine();

	}

	if (this->context->position.y - 1.0 < 0.0f) {

		this->inReverse = false;

	}
	else if (this->context->position.y + 1.0f >= this->grid->getHeight()) {

		this->inReverse = true;

	}

}

void CentipedeController::moveLeftRoutine() {

	if (this->context->position.x - 1 < 0 && this->commands.size() <= 1) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->grid->hasType(ObjectType::Mushroom,
		this->context->position.x - 1, this->context->position.y)) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->commands.size() < 1) {

		this->commands.push(new ObjectMoveLeftCommand(this->context));

	}

}

void CentipedeController::moveRightRoutine() {

	if (this->context->position.x + 1 >= this->grid->getWidth() && this->commands.size() <= 1) {

		this->changeLevelAndDirection(CentipedeDirection::Left);


	}

	else if (this->grid->hasType(ObjectType::Mushroom,
		this->context->position.x + 1, this->context->position.y)) {

		this->changeLevelAndDirection(CentipedeDirection::Left);

	}
	else if (this->commands.size() < 1) {

		this->commands.push(new ObjectMoveRightCommand(this->context));

	}

}

void CentipedeController::changeLevelAndDirection(CentipedeDirection dir) {

	this->dir = dir;
	if (!this->nextLevelBlocked()) {
		this->queueLevelChangeCommand();
	}

}

void CentipedeController::queueLevelChangeCommand() {

	if (!this->inReverse) {
		this->commands.push(new ObjectMoveDownCommand(this->context));
	}
	else {
		this->commands.push(new ObjectMoveUpCommand(this->context));
	}

}

bool CentipedeController::nextLevelBlocked() {

	if (!this->inReverse && this->grid->hasType(ObjectType::Mushroom,
		this->context->position.x, this->context->position.y + 1)) {

		return true;

	}
	else if (this->inReverse && this->grid->hasType(ObjectType::Mushroom,
		this->context->position.x, this->context->position.y - 1)) {

		return true;
	
	}

	return false;

}