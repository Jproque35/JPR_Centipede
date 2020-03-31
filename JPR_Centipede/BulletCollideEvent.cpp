#include "BulletCollideEvent.h"
#include "GameObjectManager.h"
#include "PlayerBullet.h"
#include "GameObjectState.h"
#include "CollisionMap.h"
#include "EngineLib.h"
#include "SoundManager.h"

BulletCollideEvent::BulletCollideEvent(PlayerBullet* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();
	SoundManager* sdm = SoundManager::getInstance();

	this->hitSnd.setBuffer(*sdm->get(2));

}

BulletCollideEvent::BulletCollideEvent(const BulletCollideEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

BulletCollideEvent::~BulletCollideEvent() {

	cout << "Destroying BulletCollideEvent..." << endl;

}

BulletCollideEvent& BulletCollideEvent::operator=(const BulletCollideEvent& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

GameEventListener* BulletCollideEvent::recontextCopy(GameObject* obj) {

	return new BulletCollideEvent((PlayerBullet*)obj);

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

	return obj->getType() == ObjectType::Mushroom
		|| (obj->getType() == ObjectType::CentipedeHead
		|| obj->getType() == ObjectType::CentipedeBody);

}

void BulletCollideEvent::update(float elapsedTime) {

	vector<GameObject*> intersectsObjs = EngineLib::getIntersectsObj(this->context);

	if (this->containsHittable(intersectsObjs)) {

		this->gm->remove(this->context->getId());
		this->hitSnd.play();

	}

}