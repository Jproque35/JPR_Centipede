#include "MushroomHitEvent.h"
#include "GameObjectFactory.h"
#include "GameObjectManager.h"
#include "Mushroom.h"
#include "CollisionMap.h"
#include "EngineLib.h"

MushroomHitEvent::MushroomHitEvent(Mushroom* context) {

	this->gm = GameObjectManager::getInstance();
	this->context = context;

}

MushroomHitEvent::MushroomHitEvent(const MushroomHitEvent& obj) {

	this->context = obj.context;
	this->gm = obj.gm;

}

MushroomHitEvent::~MushroomHitEvent() {

	//cout << "Deleting MushroomHitEvent..." << endl;

}

MushroomHitEvent& MushroomHitEvent::operator=(const MushroomHitEvent& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

GameEventListener* MushroomHitEvent::recontextCopy(GameObject* obj) {

	return new MushroomHitEvent((Mushroom*)obj);

}

inline bool MushroomHitEvent::containsBullet(vector<GameObject*> objs) {

	for (int i = 0; i < objs.size(); ++i) {

		if (objs[i]->getType() == ObjectType::PlayerBullet
			&& this->context->getCollisionBox().intersects(objs[i]->getCollisionBox()) ) {

			return true;

		}

	}

	return false;

}

inline void MushroomHitEvent::handleHit() {

	cout << "Handling hit" << endl;

	this->context->decrementHealth();

	if (this->context->getHealth() <= 0) {

		this->gm->remove(this->context->getId());

	}

}

void MushroomHitEvent::update(float elapsedTime) {

	vector<GameObject*> intersectObjs = EngineLib::getIntersectsObj(this->context);

	if (this->containsBullet(intersectObjs)) {

		this->handleHit();

	}

}
