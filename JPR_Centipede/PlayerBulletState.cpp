#include "PlayerBulletState.h"
#include "PlayerBullet.h"
#include "BulletCollideEvent.h"
#include "GameObjectManager.h"
#include "GameObjectFactory.h"

PlayerBulletState::PlayerBulletState(PlayerBullet* obj) {

	this->context = obj;
	this->type = StateType::PlayerBulletState;
	this->events.push_back(new BulletCollideEvent(obj));

}

PlayerBulletState::~PlayerBulletState() {

	cout << "Destroying PlayerBulletState..." << endl;

}

PlayerBulletState& PlayerBulletState::operator=(const PlayerBulletState& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

void PlayerBulletState::update(float elapsedTime) {

	float moveDist = this->context->getYSpeed() * elapsedTime;

	this->context->setY(this->context->getY() - moveDist );
	distTravelled += moveDist;
	
	this->context->setShapePosition(this->context->getX(), this->context->getY());
	this->context->setSpritePosition(this->context->getX(), this->context->getY());

	if(this->context->getY() <= 0) {

		GameObjectManager* gm = GameObjectManager::getInstance();
		this->distTravelled = 0.0f;
		gm->remove(this->context->getId());

	}

}