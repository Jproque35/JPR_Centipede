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

CentipedeBodyHitEvent::CentipedeBodyHitEvent(Centipede* context) {

	this->context = context;
	this->cm = CollisionMap::getInstance();

}

CentipedeBodyHitEvent::CentipedeBodyHitEvent(const CentipedeBodyHitEvent& obj) {

	this->context = obj.context;

}

CentipedeBodyHitEvent::~CentipedeBodyHitEvent() {

	cout << "Destructin CentipedeBodyHitEvent..." << endl;

}

CentipedeBodyHitEvent& CentipedeBodyHitEvent::operator=(const CentipedeBodyHitEvent& obj) {

	return *this;

}

GameEventListener* CentipedeBodyHitEvent::recontextCopy(GameObject* obj) {

	return new CentipedeBodyHitEvent((Centipede*)obj);

}

inline bool CentipedeBodyHitEvent::containsBullet(vector<GameObject*> objs) {

	for (int i = 0; i < objs.size(); ++i) {

		if (objs[i]->getType() == ObjectType::PlayerBullet) {

			return true;

		}

	}

	return false;

}

void CentipedeBodyHitEvent::update(float elapsedTime) {

	GameObjectManager* gm = GameObjectManager::getInstance();
	ScoreManager* scm = ScoreManager::getInstance();

	float hitX = round(this->context->getX());
	float hitY = round(this->context->getY());

	if ( this->containsBullet(EngineLib::getIntersectsObj(this->context)) ) {

		GameObjectManager* gm = GameObjectManager::getInstance();
		GameObjectFactory* objFactory = GameObjectFactory::getInstance();
		GameObject* newMushroom = objFactory->makeObject(ObjectType::Mushroom, hitX, hitY);		
		ScoreManager* scm = ScoreManager::getInstance();
		gm->add( newMushroom );
		newMushroom->init(floor(this->context->getX()), floor(this->context->getY()));

		scm->increaseScore(10);

		if (this->context->getNext() != NULL) {

			this->context->setStateType(StateType::CentipedeHeadState);
			this->context->setX(hitX);
			this->context->setY(hitY);
			this->context->getState()->clearCommands();
			this->context->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveDown, this->context) );

			
			if (this->context->getDirection() == CentipedeDirection::Left) {

				this->context->setDirection(CentipedeDirection::Right);

			}
			else {

				this->context->setDirection(CentipedeDirection::Left);

			}
		}
		else {

			gm->remove(this->context->getId());

		}

		if (this->context->getPrev() != NULL) {

			this->context->getPrev()->setNext(NULL);

		}

	}
}