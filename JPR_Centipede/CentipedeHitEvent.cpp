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

void CentipedeHitEvent::update(float elapsedTime) {

	float hitX = round(this->context->getX());
	float hitY = round(this->context->getY());

	if ( this->containsBullet( EngineLib::getIntersectsObj(this->context) ) ) {

		cout << "Centipede got hit" << endl;
		
		GameObjectFactory* objFactory = GameObjectFactory::getInstance();
		GameObject* newMushroom = objFactory->makeObject(ObjectType::Mushroom, hitX, hitY);
		gm->add(newMushroom);
		newMushroom->init(floor(this->context->getX()), floor(this->context->getY()));

		if (this->context->getNext() != NULL) {

			this->context->getNext()->setStateType( StateType::CentipedeHeadState );
			this->context->getNext()->getState()->clearCommands();
			this->context->getNext()->setX(round(this->context->getNext()->getX()));
			this->context->getNext()->setY(round(this->context->getNext()->getY()));
			this->context->getNext()->setPrev(NULL);
			this->context->getNext()->getState()->queueCommand( CommandFactory::makeCommand(CommandType::MoveDown, this->context->getNext()) );

		}

		this->gm->remove(this->context->getId());

		this->scm->increaseScore(100);
		//this->context->getData()->setPosition(Vector2f(0, 0));

	}

}