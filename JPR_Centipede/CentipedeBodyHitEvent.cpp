#include "CentipedeBodyHitEvent.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ScoreObject.h"
#include "ObjectType.h"
#include "CentipedeDirection.h"
#include "Mushroom.h"
#include "GameObjectFactory.h"
#include "GameObjectState.h"
#include "CommandFactory.h"
#include "CollisionMap.h"
#include "EngineLib.h"
#include "CentipedeManager.h"
#include "MushroomManager.h"

CentipedeBodyHitEvent::CentipedeBodyHitEvent(Centipede* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();
	this->scm = ScoreManager::getInstance();
	this->cm = CollisionMap::getInstance();

}

CentipedeBodyHitEvent::~CentipedeBodyHitEvent() {

	//cout << "Destructin CentipedeBodyHitEvent..." << endl;

}

GameEventListener* CentipedeBodyHitEvent::recontextCopy(GameObject* obj) {

	return new CentipedeBodyHitEvent((Centipede*)obj);

}

inline bool CentipedeBodyHitEvent::containsBullet(vector<GameObject*> objs) {

	for (int i = 0; i < objs.size(); ++i) {

		if (objs[i]->getType() == ObjectType::PlayerBullet
			&& this->context->getCollisionBox().intersects(objs[i]->getCollisionBox()) ) {

			return true;

		}

	}

	return false;

}

inline void CentipedeBodyHitEvent::reverseContextDirection() {

	if (this->context->getDirection() == CentipedeDirection::Left) {

		this->context->setDirection(CentipedeDirection::Right);

	}
	else {

		this->context->setDirection(CentipedeDirection::Left);

	}

}

inline void CentipedeBodyHitEvent::changeContextToHead(float hitX, float hitY) {

	this->context->setStateType(StateType::CentipedeHeadState);
	//this->context->setX(hitX);
	//this->context->setY(hitY);
	//this->context->getState()->clearCommands();
	//this->context->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveDown, this->context));

	this->reverseContextDirection();

}

void CentipedeBodyHitEvent::update(float elapsedTime) {

	float hitX = round(this->context->getX());
	float hitY = round(this->context->getY());

	if ( this->containsBullet(EngineLib::getIntersectsObj(this->context)) ) {

		MushroomManager* shroomMngr = MushroomManager::getInstance();

		cout << "Centipede got hit" << endl;

		shroomMngr->addMushroom(round(this->context->getPosition().x), round(this->context->getPosition().y));

		this->scm->increaseScore(10);

		if (this->context->getNext() != NULL) {

			this->changeContextToHead(hitX, hitY);

		}
		else {

			gm->remove(this->context->getId());

			CentipedeManager* centiMngr = CentipedeManager::getInstance();
			centiMngr->setNumActive(centiMngr->getNumActive() - 1);

		}

		if (this->context->getPrev() != NULL) {

			this->context->getPrev()->setNext(NULL);

		}

	}
}