#include "BulletFiredEvent.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "PlayerBullet.h"
#include "GameObjectState.h"
#include "CommandFactory.h"

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

		GameObject* player = this->gm->get(0);

			cout << "Fired object " << this->context << endl;



			if (this->context->getState()->getNumCommands() < 1) {

				this->context->setX(player->getX());
				this->context->setY(player->getY());

				this->context->getState()->queueCommand(
					CommandFactory::makeCommand(CommandType::ShootBullet, this->context));

			}

	}

}