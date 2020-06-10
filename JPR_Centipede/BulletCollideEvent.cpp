#include "BulletCollideEvent.h"
#include "GameObjectManager.h"
#include "PlayerBullet.h"
#include "GameObjectState.h"
#include "CollisionMap.h"
#include "EngineLib.h"
#include "SoundManager.h"
#include "Centipede.h"
#include "Mushroom.h"

BulletCollideEvent::BulletCollideEvent(PlayerBullet* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();
	SoundManager* sdm = SoundManager::getInstance();

	this->hitSnd.setBuffer(*sdm->get(2));

}

BulletCollideEvent::~BulletCollideEvent() {

	//cout << "Destroying BulletCollideEvent..." << endl;

}

bool BulletCollideEvent::containsHittable(vector<GameObject*> objs) {

	for (int i = 0; i < objs.size(); ++i) {

		if ( this->isHittable(objs[i])
			&& this->context->getCollisionBox().intersects(objs[i]->getCollisionBox() ) ) {

			return true;

		}

	}

	return false;

}

inline bool BulletCollideEvent::isHittable(GameObject* obj) {

	return dynamic_cast<Mushroom*>(obj) != NULL
		|| dynamic_cast<Centipede*>(obj) != NULL;

}

void BulletCollideEvent::update(float elapsedTime) {

	vector<GameObject*> intersectsObjs = EngineLib::getIntersectsObj(this->context);

	if (this->containsHittable(intersectsObjs)) {

		this->gm->remove(this->context->getId());
		this->hitSnd.play();

	}

}