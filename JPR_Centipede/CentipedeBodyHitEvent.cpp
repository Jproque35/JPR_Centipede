#include "CentipedeBodyHitEvent.h"


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

	Vector2f currPos = this->context->getData()->getPosition();
	GameObjectManager* gm = GameObjectManager::getInstance();
	ScoreManager* scm = ScoreManager::getInstance();

	if (gm->hasType(ObjectType::PlayerProjectile, currPos.x, currPos.y)) {

		CentipedeData* data = (CentipedeData*)(this->context->getData());

		cout << "Centipede got hit" << endl;
		
		if (data->getDirection() == CentipedeDirection::Left) {

			data->setDirection(CentipedeDirection::Right);

		}
		else {

			data->setDirection(CentipedeDirection::Left);

		}

		this->context->setState(new CentipedeHeadState(data));

		scm->increaseScore(10);
		//this->context->getData()->setPosition(Vector2f(0, 0));

	}
}