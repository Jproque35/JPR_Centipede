#include "CentipedeHitEvent.h"
#include "GameObjectManager.h"
#include "ScoreObject.h"
#include "Centipede.h"
#include "StateTypes.h"

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

	if (this->gm->hasType(ObjectType::PlayerBullet, this->context->getX(), this->context->getY())) {

		cout << "Centipede got hit" << endl;
		
		if (this->context->getNext() != NULL) {

			this->context->getNext()->setStateType( StateType::CentipedeHeadState );
			this->context->getNext()->setPrev(NULL);

		}

		this->gm->erase(this->context->getId());

		this->scm->increaseScore(100);
		//this->context->getData()->setPosition(Vector2f(0, 0));

	}

}