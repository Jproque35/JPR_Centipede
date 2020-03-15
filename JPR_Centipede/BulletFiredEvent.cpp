#include "BulletFiredEvent.h"

BulletFiredEvent::BulletFiredEvent(PlayerBullet* context) {

	this->im = InputManager::getInstance();
	this->gm = GameObjectManager::getInstance();
	this->context = context;

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

	if (this->im->isFirePressed()) {

		if (!this->context->getData()->isActive()) {

			GameObject* player = this->gm->get(0);
			Vector2f playerPos = player->getData()->getPosition();
			float xPos = playerPos.x + player->getData()->getShape().getRadius() - this->context->getData()->getShape().getRadius();

			cout << "Fired object " << this->context << endl;

			if (this->context->commandQueueSize() < 1) {

				Vector2f newPos;
				newPos.x = xPos;
				newPos.y = playerPos.y;
				this->context->getData()->setPosition(newPos);

				this->context->queueCommand(CommandFactory::makeCommand(CommandType::ShootBullet,
					this->context->getData()));

			}


		}

	}

}