#include "CentipedeMoveEvent.h"

CentipedeMoveEvent::CentipedeMoveEvent(Centipede* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();
	this->data = (CentipedeData*)this->context->getData();

}

CentipedeMoveEvent::CentipedeMoveEvent(const CentipedeMoveEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;
	this->data = obj.data;

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

	if (floor(this->data->getPosition().y - 1.0f) < 0) {

		this->data->unsetReversed();

	}
	else if (ceil(this->data->getPosition().y + 1.0f) >= this->gm->getGridHeight()) {

		this->data->setReversed();

	}

}

void CentipedeMoveEvent::moveLeftRoutine() {

	if (this->leftBlocked() && this->context->commandsSize() < 1) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->context->commandsSize() < 1) {

		this->context->queueCommand(CommandFactory::makeCommand(CommandType::MoveLeft, this->context->getData()));

	}

}

void CentipedeMoveEvent::moveRightRoutine() {

	if (this->rightBlocked() && this->context->commandsSize() < 1) {

		this->changeLevelAndDirection(CentipedeDirection::Left);

	}
	else if (this->context->commandsSize() < 1) {

		this->context->queueCommand(CommandFactory::makeCommand(CommandType::MoveRight, this->context->getData()));

	}

}

void CentipedeMoveEvent::changeLevelAndDirection(CentipedeDirection dir) {

	this->data->setDirection(dir);

	if (!this->nextLevelBlocked()) {

		cout << "Next level not blocked: " << this->data->getPosition().x << ", " << this->data->getPosition().y << endl;
		this->queueLevelChangeCommand();

	}
	else {

		cout << "Next level IS blocked" << this->data->getPosition().x << ", " << this->data->getPosition().y << endl;

	}

}

void CentipedeMoveEvent::queueLevelChangeCommand() {

	if (!this->data->isReversed()) {

		this->context->queueCommand(CommandFactory::makeCommand(CommandType::MoveDown, this->data));

	}
	else {

		this->context->queueCommand(CommandFactory::makeCommand(CommandType::MoveUp, this->data));

	}

}

inline bool CentipedeMoveEvent::nextLevelBlocked() {

	if (!this->data->isReversed() && this->downBlocked()) {

		return true;

	}
	else if (this->data->isReversed() && this->upBlocked()) {

		return true;

	}

	return false;

}

inline bool CentipedeMoveEvent::leftBlocked() {

	Vector2f currPos = this->data->getPosition();

	int xDest = floor(currPos.x - 1.0f);

	if (xDest < 0) {

		return true;

	}
	else if (this->gm->hasType(ObjectType::MushroomData, xDest, floor(currPos.y))) {

		return true;

	}

	return false;

}

inline bool CentipedeMoveEvent::rightBlocked() {

	Vector2f currPos = this->data->getPosition();
	int xDest = ceil(currPos.x + 1.0f);

	if (xDest >= this->gm->getGridWidth()) {

		return true;

	}
	else if (this->gm->hasType(ObjectType::MushroomData, xDest, floor(currPos.y))) {

		return true;

	}

	return false;

}

inline bool CentipedeMoveEvent::upBlocked() {

	Vector2f currPos = this->data->getPosition();

	int xDest = floor(currPos.x);

	if (this->data->getDirection() == CentipedeDirection::Right) {

		xDest = ceil(currPos.x);

	}

	int yDest = floor(currPos.y - 1.0f);

	cout << "Checking position " << xDest << ", " << yDest << endl;

	if (yDest < 0) {

		return true;

	}
	else if (this->gm->hasType(ObjectType::MushroomData, currPos.x, yDest)) {

		return true;

	}

	return false;

}

inline bool CentipedeMoveEvent::downBlocked() {

	Vector2f currPos = this->data->getPosition();

	int xDest = floor(currPos.x);

	if (this->data->getDirection() == CentipedeDirection::Right) {

		xDest = ceil(currPos.x);

	}

	int yDest = ceil(currPos.y + 1.0f);

	cout << "Checking position " << xDest << ", " << yDest << endl;

	if (yDest >= this->gm->getGridHeight()) {

		return true;

	}
	else if (this->gm->hasType(ObjectType::MushroomData, currPos.x, yDest)) {

		return true;

	}

	return false;

}