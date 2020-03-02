#include "CentipedeHitEvent.h"

CentipedeHitEvent::CentipedeHitEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (CentipedeController*)(this->gm->get(i));

}

CentipedeHitEvent::CentipedeHitEvent(const CentipedeHitEvent& obj) {

	this->gm = obj.gm;
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

	}

}