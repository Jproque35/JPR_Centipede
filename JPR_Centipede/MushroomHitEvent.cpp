#include "MushroomHitEvent.h"

MushroomHitEvent::MushroomHitEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (MushroomController*)(this->gm->get(i));

}

void MushroomHitEvent::update(float elapsedTime) {

	Vector2f currPos = this->context->getData()->getPosition();

	if (this->gm->hasType(ObjectType::PlayerProjectile, currPos.x, currPos.y)) {

		cout << "Mushroom got hit" << endl;

	}

}
