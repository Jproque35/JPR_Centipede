#include "BulletCollideEvent.h"
#include "GameObjectManager.h"
#include "PlayerBullet.h"
#include "GameObjectState.h"

BulletCollideEvent::BulletCollideEvent(PlayerBullet* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();

}

BulletCollideEvent::BulletCollideEvent(const BulletCollideEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

BulletCollideEvent::~BulletCollideEvent() {}

BulletCollideEvent& BulletCollideEvent::operator=(const BulletCollideEvent& obj) {

	return *this;

}

void BulletCollideEvent::update(float elapsedTime) {

	vector<GameObject*> gm = this->gm->get(this->context->getX(), this->context->getY());

	for (int i = 0; i < gm.size(); i++) {

		if (gm[i] != NULL) {

			if (gm[i]->getType() == ObjectType::Mushroom
				|| gm[i]->getType() == ObjectType::CentipedeHead) {

				this->context->getState()->clearCommands();
				this->context->setX(-1.0f);
				this->context->setY(-1.0f);

			}

		}

	}

}