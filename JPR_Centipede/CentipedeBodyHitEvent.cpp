#include "CentipedeBodyHitEvent.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ScoreObject.h"
#include "ObjectType.h"
#include "CentipedeDirection.h"
#include "Mushroom.h"
#include "GameObjectFactory.h"

CentipedeBodyHitEvent::CentipedeBodyHitEvent(Centipede* context) {

	this->context = context;

}

CentipedeBodyHitEvent::CentipedeBodyHitEvent(const CentipedeBodyHitEvent& obj) {

	this->context = obj.context;

}

CentipedeBodyHitEvent::~CentipedeBodyHitEvent() {}

CentipedeBodyHitEvent& CentipedeBodyHitEvent::operator=(const CentipedeBodyHitEvent& obj) {

	return *this;

}

void CentipedeBodyHitEvent::update(float elapsedTime) {

	GameObjectManager* gm = GameObjectManager::getInstance();
	ScoreManager* scm = ScoreManager::getInstance();

	if (gm->hasType(ObjectType::PlayerBullet, this->context->getX(), this->context->getY())) {

		GameObjectManager* gm = GameObjectManager::getInstance();
		GameObjectFactory* objFactory = GameObjectFactory::getInstance();
		GameObject* newMushroom = objFactory->makeObject(ObjectType::Mushroom, this->context->getX(), this->context->getY());		
		gm->add( newMushroom );
		newMushroom->init(floor(this->context->getX()), floor(this->context->getY()));

		if (this->context->getNext() != NULL) {
			this->context->setStateType(StateType::CentipedeHeadState);
			this->context->setX(floor(this->context->getX()));
			this->context->setY(floor(this->context->getY()));

			/*
			if (this->context->getDirection() == CentipedeDirection::Left) {

				this->context->setDirection(CentipedeDirection::Right);

			}
			else {

				this->context->setDirection(CentipedeDirection::Left);

			}*/
		}
		else {

			gm->erase(this->context->getId());

		}

		if (this->context->getPrev() != NULL) {

			this->context->getPrev()->setNext(NULL);

		}

	}
}