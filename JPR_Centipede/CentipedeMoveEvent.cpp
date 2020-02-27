#include "CentipedeMoveEvent.h"

CentipedeMoveEvent::CentipedeMoveEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (CentipedeController*)(gm->get(i));

}

void CentipedeMoveEvent::update(float elapsedTime) {

	if (this->context->dir == CentipedeDirection::Left) {

		this->moveLeftRoutine();

	}
	else if (this->context->dir == CentipedeDirection::Right) {

		this->moveRightRoutine();

	}

	if (this->context->getData()->getPosition().y - 1.0 < 0.0f) {

		this->inReverse = false;

	}
	else if (this->context->getData()->getPosition().y + 1.0f >= this->gm->getGridHeight()) {

		this->inReverse = true;

	}

}

void CentipedeMoveEvent::moveLeftRoutine() {

	if (this->context->getData()->getPosition().x - 1 < 0 && this->context->commands.size() <= 1) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->gm->hasType(ObjectType::Mushroom,
		this->context->getData()->getPosition().x - 1, this->context->getData()->getPosition().y)) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->context->commands.size() < 1) {

		this->context->commands.push(new ObjectMoveLeftCommand(this->context->getData()));

	}

}

void CentipedeMoveEvent::moveRightRoutine() {

	if (this->context->getData()->getPosition().x + 1 >= this->gm->getGridWidth() && this->context->commands.size() <= 1) {

		this->changeLevelAndDirection(CentipedeDirection::Left);


	}

	else if (this->gm->hasType(ObjectType::Mushroom,
		this->context->getData()->getPosition().x + 1, this->context->getData()->getPosition().y)) {

		this->changeLevelAndDirection(CentipedeDirection::Left);

	}
	else if (this->context->commands.size() < 1) {

		this->context->commands.push(new ObjectMoveRightCommand(this->context->getData()));

	}

}

void CentipedeMoveEvent::changeLevelAndDirection(CentipedeDirection dir) {

	this->context->dir = dir;
	if (!this->nextLevelBlocked()) {
		this->queueLevelChangeCommand();
	}

}

void CentipedeMoveEvent::queueLevelChangeCommand() {

	if (!this->inReverse) {
		this->context->commands.push(new ObjectMoveDownCommand(this->context->getData()));
	}
	else {
		this->context->commands.push(new ObjectMoveUpCommand(this->context->getData()));
	}

}

bool CentipedeMoveEvent::nextLevelBlocked() {

	if (!this->inReverse && this->gm->hasType(ObjectType::Mushroom,
		this->context->getData()->getPosition().x, this->context->getData()->getPosition().y + 1)) {

		return true;

	}
	else if (this->inReverse && this->gm->hasType(ObjectType::Mushroom,
		this->context->getData()->getPosition().x, this->context->getData()->getPosition().y - 1)) {

		return true;

	}

	return false;

}