#include "MushroomHitEvent.h"
#include "GameObjectFactory.h"
#include "GameObjectManager.h"
#include "Mushroom.h"

MushroomHitEvent::MushroomHitEvent(Mushroom* context) {

	this->gm = GameObjectManager::getInstance();
	this->context = context;

}

MushroomHitEvent::MushroomHitEvent(const MushroomHitEvent& obj) {

	this->context = obj.context;
	this->gm = obj.gm;

}

MushroomHitEvent::~MushroomHitEvent() {

	cout << "Deleting MushroomHitEvent..." << endl;

}

MushroomHitEvent& MushroomHitEvent::operator=(const MushroomHitEvent& obj) {

	return *this;

}

void MushroomHitEvent::update(float elapsedTime) {

	if (this->gm->hasType(ObjectType::PlayerBullet, this->context->getX(), this->context->getY())) {


		this->context->decrementHealth();
		cout << "Mushroom got hit, HP is " << this->context->getHealth() << endl;

		if (this->context->getHealth() <= 0) {

 			this->gm->erase(this->context->getId());

		}
	}

}
