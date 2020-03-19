#include "CentipedeBodyHitEvent.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ScoreObject.h"
#include "ObjectType.h"
#include "CentipedeDirection.h"

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

		cout << "Centipede got hit" << endl;
		
		if (this->context->getDirection() == CentipedeDirection::Left) {

			this->context->setDirection(CentipedeDirection::Right);

		}
		else {

			this->context->setDirection(CentipedeDirection::Left);

		}

		//this->context->setState(new CentipedeHeadState(data));

		scm->increaseScore(10);

	}
}