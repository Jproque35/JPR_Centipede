#include "CentipedeMoveEvent.h"
#include "GameObjectManager.h"
#include "Centipede.h"
#include "GameObjectState.h"
#include "CommandFactory.h"
#include "CollisionMap.h"
#include "EngineLib.h"

CentipedeMoveEvent::CentipedeMoveEvent(Centipede* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();
	this->cm = CollisionMap::getInstance();

}

CentipedeMoveEvent::CentipedeMoveEvent(const CentipedeMoveEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

CentipedeMoveEvent::~CentipedeMoveEvent() {

	cout << "Destroying CentipedeMoveEvent..." << endl;

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

inline bool CentipedeMoveEvent::intersectsMushroom(float xPos, float yPos) {

	vector<GameObject*> objs = EngineLib::getIntersectsPt(xPos, yPos);

	for (int i = 0; i < objs.size(); ++i) {

		if (objs[i]->getType() == ObjectType::Mushroom) {

			return true;

		}

	}

	return false;

}

void CentipedeMoveEvent::update(float elapsedTime) {

	float xMoveDist = this->context->getXSpeed() * elapsedTime;
	float yMoveDist = this->context->getYSpeed() * elapsedTime;

	if (this->context->getDirection() == CentipedeDirection::Left) {

		this->moveLeftRoutine(xMoveDist);

	}
	else if (this->context->getDirection() == CentipedeDirection::Right) {

		this->moveRightRoutine(xMoveDist);

	}

	if (this->context->getY() - yMoveDist < 0) {

		this->context->unsetReversed();

	}
	else if (this->context->getY() + yMoveDist >= this->cm->getHeight()) {

		this->context->setReversed();

	}

}

void CentipedeMoveEvent::moveLeftRoutine(float moveDist) {

	if (this->intersectsMushroom(this->context->getX() - moveDist, this->context->getY()) 
		&& this->context->getState()->getNumCommands() < 1) {

		this->changeLevelAndDirection(CentipedeDirection::Right);

	}
	else if (this->context->getState()->getNumCommands() < 1) {

		this->context->getState()->queueCommand(
			CommandFactory::makeCommand(CommandType::MoveLeft, this->context) );

	}

}

void CentipedeMoveEvent::moveRightRoutine(float moveDist) {

	if (this->intersectsMushroom(this->context->getX() + moveDist, this->context->getY() )
		&& this->context->getState()->getNumCommands() < 1) {

		this->changeLevelAndDirection(CentipedeDirection::Left);

	}
	else if (this->context->getState()->getNumCommands() < 1) {

		this->context->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveRight, this->context));

	}

}

inline void CentipedeMoveEvent::changeLevelAndDirection(CentipedeDirection dir) {

	this->context->setDirection(dir);
	this->queueLevelChangeCommand();

}

void CentipedeMoveEvent::queueLevelChangeCommand() {

	if (!this->context->isReversed()) {

		this->context->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveDown, this->context));

	}
	else {

		this->context->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveUp, this->context));

	}

}