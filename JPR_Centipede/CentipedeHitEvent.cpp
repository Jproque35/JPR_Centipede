#include "CentipedeHitEvent.h"
#include "GameObjectManager.h"
#include "CollisionMap.h"
#include "ScoreObject.h"
#include "Centipede.h"
#include "StateTypes.h"
#include "GameObjectFactory.h"
#include "GameObjectState.h"
#include "EngineLib.h"
#include "CommandFactory.h"
#include "CommandType.h"
#include "CentipedeManager.h"

CentipedeHitEvent::CentipedeHitEvent(Centipede* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();
	this->cm = CollisionMap::getInstance();
	this->scm = ScoreManager::getInstance();

}

CentipedeHitEvent::CentipedeHitEvent(const CentipedeHitEvent& obj) {

	this->gm = GameObjectManager::getInstance();
	this->scm = ScoreManager::getInstance();
	this->context = obj.context;

}

CentipedeHitEvent::~CentipedeHitEvent() {

	cout << "Destroying CentipedeHitEvent..." << endl;

}

CentipedeHitEvent& CentipedeHitEvent::operator=(const CentipedeHitEvent& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

GameEventListener* CentipedeHitEvent::recontextCopy(GameObject* obj) {

	return new CentipedeHitEvent((Centipede*)obj);

}

inline bool CentipedeHitEvent::containsBullet(vector<GameObject*> objs) {

	for (int i = 0; i < objs.size(); ++i) {

		if (objs[i]->getType() == ObjectType::PlayerBullet
			&& this->context->getCollisionBox().intersects(objs[i]->getCollisionBox()) ) {

			return true;

		}

	}

	return false;

}

inline void CentipedeHitEvent::layMushroom() {

	GameObjectFactory* objFactory = GameObjectFactory::getInstance();
	GameObject* newMushroom = objFactory->makeObject(ObjectType::Mushroom, 
		round(this->context->getX()), round(this->context->getY()));

	gm->add(newMushroom);
	newMushroom->init(floor(this->context->getX()), floor(this->context->getY()));

}

inline void CentipedeHitEvent::processNext(Centipede* next) {

	next->setStateType(StateType::CentipedeHeadState);
	next->getState()->clearCommands();
	next->setX(round(this->context->getNext()->getX()));
	next->setY(round(this->context->getNext()->getY()));
	next->setPrev(NULL);
	next->getState()->queueCommand(CommandFactory::makeCommand(CommandType::MoveDown, this->context->getNext()));

}

void CentipedeHitEvent::update(float elapsedTime) {

	if ( this->containsBullet( EngineLib::getIntersectsObj(this->context) ) ) {

		cout << "Centipede got hit" << endl;
		
		this->layMushroom();

		if (this->context->getNext() != NULL) {

			this->processNext(this->context->getNext());

		}

		this->gm->remove(this->context->getId());
		
		CentipedeManager* centiMngr = CentipedeManager::getInstance();

		centiMngr->setNumActive( centiMngr->getNumActive() - 1 );

		this->scm->increaseScore(100);

	}

}