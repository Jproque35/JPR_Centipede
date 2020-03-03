#include "MushroomHitEvent.h"

MushroomHitEvent::MushroomHitEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (Mushroom*)(this->gm->get(i));

}

MushroomHitEvent::MushroomHitEvent(const MushroomHitEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

MushroomHitEvent::~MushroomHitEvent() {}

MushroomHitEvent& MushroomHitEvent::operator=(const MushroomHitEvent& obj) {

	return *this;

}

void MushroomHitEvent::update(float elapsedTime) {

	Vector2f currPos = this->context->getData()->getPosition();

	if (this->gm->hasType(ObjectType::PlayerProjectile, currPos.x, currPos.y)) {

		cout << "Mushroom got hit" << endl;

	}

}
