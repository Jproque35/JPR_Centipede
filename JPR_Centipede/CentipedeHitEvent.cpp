#include "CentipedeHitEvent.h"

CentipedeHitEvent::CentipedeHitEvent(Centipede* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();
	this->scm = ScoreManager::getInstance();

}

CentipedeHitEvent::CentipedeHitEvent(const CentipedeHitEvent& obj) {

	this->gm = GameObjectManager::getInstance();
	this->scm = ScoreManager::getInstance();
	this->context = obj.context;

}

CentipedeHitEvent::~CentipedeHitEvent() {}

CentipedeHitEvent& CentipedeHitEvent::operator=(const CentipedeHitEvent& obj) {

	return *this;

}

void CentipedeHitEvent::update(float elapsedTime) {

	Vector2f currPos = this->context->getData()->getPosition();

	if (this->gm->hasType(ObjectType::PlayerProjectile, currPos.x, currPos.y)) {

		cout << "Centipede got hit" << endl;
		this->scm->increaseScore(10);
		//this->context->getData()->setPosition(Vector2f(0, 0));

	}

}