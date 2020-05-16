#include "CentipedeMoveEvent.h"
#include "GameObjectManager.h"
#include "Centipede.h"
#include "GameObjectState.h"
#include "CommandFactory.h"
#include "CollisionMap.h"
#include "SoundManager.h"

CentipedeMoveEvent::CentipedeMoveEvent(Centipede* context) {

	this->context = context;
	this->cm = CollisionMap::getInstance();
	this->gm = GameObjectManager::getInstance();
	SoundManager* sdm = SoundManager::getInstance();
	this->turnSnd.setBuffer(*sdm->get(1));

}

CentipedeMoveEvent::CentipedeMoveEvent(const CentipedeMoveEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

CentipedeMoveEvent::~CentipedeMoveEvent() {

	//cout << "Destroying CentipedeMoveEvent..." << endl;

}

CentipedeMoveEvent& CentipedeMoveEvent::operator=(const CentipedeMoveEvent& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

GameEventListener* CentipedeMoveEvent::recontextCopy(GameObject* obj) {

	return new CentipedeMoveEvent((Centipede*)obj);

}

void CentipedeMoveEvent::update(float elapsedTime) {

	if (this->context->getDirection() == CentipedeDirection::Left) {

		this->moveLeftRoutine();

	}
	else if (this->context->getDirection() == CentipedeDirection::Right) {

		this->moveRightRoutine();

	}

	if (floor(this->context->getY() - 1.0f) < this->cm->getHeight() * 0.6f) {

		this->context->unsetReversed();

	}
	else if (ceil(this->context->getY() + 1.0f) >= this->cm->getHeight()) {

		this->context->setReversed();

	}

}

inline void CentipedeMoveEvent::moveLeftRoutine() {

	if (this->leftBlocked() && this->context->getState()->getNumCommands() < 1) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->context->getState()->getNumCommands() < 1) {

		this->context->getState()->queueCommand(
			CommandFactory::makeCommand(CommandType::MoveLeft, this->context));

	}

}

inline void CentipedeMoveEvent::moveRightRoutine() {

	if (this->rightBlocked() && this->context->getState()->getNumCommands() < 1) {

		this->changeLevelAndDirection(CentipedeDirection::Left);

	}
	else if (this->context->getState()->getNumCommands() < 1) {

		this->context->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveRight, this->context));

	}

}

inline void CentipedeMoveEvent::changeLevelAndDirection(CentipedeDirection dir) {

	this->turnSnd.play();
	this->context->setDirection(dir);
	this->queueLevelChangeCommand();

}

inline void CentipedeMoveEvent::queueLevelChangeCommand() {

	if (!this->context->isReversed()) {

		this->context->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveDown, this->context));

	}
	else {

		this->context->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveUp, this->context));

	}

}

inline bool CentipedeMoveEvent::leftBlocked() {

	int xDest = floor(this->context->getX() - 1.0f);

	if (xDest < 0) {

		return true;

	}
	else if (this->cm->containsType(ObjectType::Mushroom, xDest, floor(this->context->getY()))) {

		return true;

	}

	return false;

}

inline bool CentipedeMoveEvent::rightBlocked() {

	int xDest = ceil(this->context->getX() + 1.0f);

	if (xDest >= this->cm->getWidth()) {

		return true;

	}
	else if (this->cm->containsType(ObjectType::Mushroom, xDest, floor(this->context->getY()))) {

		return true;

	}

	return false;

}