#include "CentipedeMoveEvent.h"

CentipedeMoveEvent::CentipedeMoveEvent(GameObjectManager* gm, Centipede* context) {

	this->gm = gm;
	this->context = context;
	this->data = (CentipedeData*)this->context->getData();

}

CentipedeMoveEvent::CentipedeMoveEvent(const CentipedeMoveEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

CentipedeMoveEvent::~CentipedeMoveEvent() {



}

CentipedeMoveEvent& CentipedeMoveEvent::operator=(const CentipedeMoveEvent& obj) {

	return *this;

}

void CentipedeMoveEvent::update(float elapsedTime) {

	if (this->data->getDirection() == CentipedeDirection::Left) {

		this->moveLeftRoutine();

	}
	else if (this->data->getDirection() == CentipedeDirection::Right) {

		this->moveRightRoutine();

	}

	if (this->context->getData()->getPosition().y - 1.0 < 0.0f) {

		this->data->unsetReversed();

	}
	else if (ceil(this->context->getData()->getPosition().y + 1.0f) >= this->gm->getGridHeight()) {

		this->data->setReversed();

	}

}

void CentipedeMoveEvent::moveLeftRoutine() {

	if (this->context->getData()->getPosition().x - 1 < 0 && this->context->commandsSize() <= 1) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->gm->hasType(ObjectType::MushroomData,
		this->context->getData()->getPosition().x - 1, this->context->getData()->getPosition().y)) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->context->commandsSize() < 1) {

		this->context->queueCommand(CommandFactory::makeCommand(CommandType::MoveLeft, this->context->getData()));

	}

}

void CentipedeMoveEvent::moveRightRoutine() {

	if (ceil(this->context->getData()->getPosition().x) + 1 >= this->gm->getGridWidth() && this->context->commandsSize() <= 1) {

		this->changeLevelAndDirection(CentipedeDirection::Left);


	}

	else if (this->gm->hasType(ObjectType::MushroomData,
		ceil(this->context->getData()->getPosition().x) + 1, floor(this->context->getData()->getPosition().y))) {

		this->changeLevelAndDirection(CentipedeDirection::Left);

	}
	else if (this->context->commandsSize() < 1) {

		this->context->queueCommand(CommandFactory::makeCommand(CommandType::MoveRight, this->context->getData()));

	}

}

void CentipedeMoveEvent::changeLevelAndDirection(CentipedeDirection dir) {

	this->data->setDirection(dir);

	if (!this->nextLevelBlocked()) {
		this->queueLevelChangeCommand();
	}

}

void CentipedeMoveEvent::queueLevelChangeCommand() {

	CentipedeData* data = (CentipedeData*)(this->context->getData());

	if (!this->data->isReversed()) {
		this->context->queueCommand(CommandFactory::makeCommand(CommandType::MoveDown, this->context->getData()));
	}
	else {
		this->context->queueCommand(CommandFactory::makeCommand(CommandType::MoveUp, this->context->getData()));
	}

}

bool CentipedeMoveEvent::nextLevelBlocked() {

	if (!this->data->isReversed() && this->gm->hasType(ObjectType::MushroomData,
		this->context->getData()->getPosition().x, ceil(this->context->getData()->getPosition().y) + 1)) {

		return true;

	}
	else if (this->data->isReversed() && this->gm->hasType(ObjectType::MushroomData,
		this->context->getData()->getPosition().x, this->context->getData()->getPosition().y - 1)) {

		return true;

	}

	return false;

}