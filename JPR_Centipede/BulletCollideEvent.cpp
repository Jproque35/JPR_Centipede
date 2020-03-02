#include "BulletCollideEvent.h"

BulletCollideEvent::BulletCollideEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (PlayerBulletController*)(this->gm->get(i));

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

	Vector2f currPos = this->context->getData()->getPosition();
	vector<ObjectController*> gm = this->gm->get(currPos.x, currPos.y);

	for (int i = 0; i < gm.size(); i++) {

		if (gm[i] != NULL) {

			if (gm[i]->getData()->getType() == ObjectType::Mushroom
				|| gm[i]->getData()->getType() == ObjectType::Centipede) {

				this->context->clearCommands();
				this->context->getData()->deactivate();

			}

		}

	}

}