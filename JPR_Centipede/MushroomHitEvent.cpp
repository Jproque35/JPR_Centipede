#include "MushroomHitEvent.h"
#include "GameObjectFactory.h"
#include "GameObjectManager.h"
#include "Mushroom.h"
#include "PlayerBullet.h"
#include "CollisionMap.h"
#include "EngineLib.h"

MushroomHitEvent::MushroomHitEvent(Mushroom* context) {

	this->gm = GameObjectManager::getInstance();
	this->context = context;

}

MushroomHitEvent::~MushroomHitEvent() {

	//cout << "Deleting MushroomHitEvent..." << endl;

}

inline bool MushroomHitEvent::containsBullet(vector<GameObject*> objs) {

	for (int i = 0; i < objs.size(); ++i) {

		PlayerBullet* obj = dynamic_cast<PlayerBullet*>(objs[i]);

		if (obj != NULL
			&& this->context->getCollisionBox().intersects(obj->getCollisionBox()) ) {

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
