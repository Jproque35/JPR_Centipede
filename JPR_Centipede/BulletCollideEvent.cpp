#include "BulletCollideEvent.h"

BulletCollideEvent::BulletCollideEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (PlayerBulletController*)(this->gm->get(i));

}

BulletCollideEvent::~BulletCollideEvent() {



}

void BulletCollideEvent::update(float elapsedTime) {

	Vector2f currPos = this->context->getData()->getPosition();
	vector<ObjectController*> objs = this->gm->get(currPos.x, currPos.y);

	for (int i = 0; i < objs.size(); i++) {

		if (objs[i] != NULL) {

			if (objs[i]->getData()->getType() == ObjectType::Mushroom
				|| objs[i]->getData()->getType() == ObjectType::Centipede) {

				this->context->clearCommands();
				this->context->getData()->deactivate();

			}

		}

	}

}