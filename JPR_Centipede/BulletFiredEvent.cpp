#include "BulletFiredEvent.h"

BulletFiredEvent::BulletFiredEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (PlayerBulletController*)(gm->get(i));

}

BulletFiredEvent::BulletFiredEvent(const BulletFiredEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

BulletFiredEvent::~BulletFiredEvent() {}

BulletFiredEvent& BulletFiredEvent::operator=(const BulletFiredEvent& obj) {

	return *this;

}

void BulletFiredEvent::update(float elapsedTime) {

	if (Keyboard::isKeyPressed(Keyboard::Space)) {

		if (!this->context->getData()->isActive()) {

			ObjectController* player = this->gm->get(0);
			Vector2f playerPos = player->getData()->getPosition();
			float xPos = playerPos.x + player->getData()->getShape().getRadius() - this->context->getData()->getShape().getRadius();

			cout << "Fired object " << this->context << endl;
			this->context->setKey(Keyboard::Space, xPos, playerPos.y);

		}

	}

}