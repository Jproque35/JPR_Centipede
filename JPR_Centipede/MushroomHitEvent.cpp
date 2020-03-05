#include "MushroomHitEvent.h"

MushroomHitEvent::MushroomHitEvent(GameObjectManager* gm, Mushroom* context) {

	this->gm = gm;
	this->context = context;
	this->data = (MushroomData*)(this->context->getData());

}

MushroomHitEvent::MushroomHitEvent(const MushroomHitEvent& obj) {

	this->data = obj.data;
	this->context = obj.context;
	this->gm = obj.gm;

}

MushroomHitEvent::~MushroomHitEvent() {}

MushroomHitEvent& MushroomHitEvent::operator=(const MushroomHitEvent& obj) {

	return *this;

}

void MushroomHitEvent::update(float elapsedTime) {

	Vector2f currPos = this->context->getData()->getPosition();

	if (this->gm->hasType(ObjectType::PlayerProjectile, currPos.x, currPos.y)) {



		if (this->data->isActive()) {

			this->data->decrementHealth();
			cout << "Mushroom got hit, HP is " << this->data->getHealth() << endl;

			if (this->data->getHealth() <= 0) {

				this->data->deactivate();
				this->data->setPosition(Vector2f(-1.0f, -1.0f));

			}
		}

	}

}
