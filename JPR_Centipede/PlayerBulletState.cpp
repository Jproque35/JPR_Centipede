#include "PlayerBulletState.h"
#include "PlayerBullet.h"
#include "BulletFiredEvent.h"
#include "BulletCollideEvent.h"
#include "PlayerBulletFireCommand.h"
#include "GameObjectManager.h"
#include "GameObjectFactory.h"

PlayerBulletState::PlayerBulletState(PlayerBullet* obj) {

	this->context = obj;
	this->type = StateType::PlayerBulletState;
	this->events.push_back(new BulletCollideEvent(obj));

}

void PlayerBulletState::update(float elapsedTime) {

	if (this->distTravelled == 0.0f) {

		//cout << "Bullet start at " << this->context->getX() << ", " << this->context->getY() << endl;

	}

	float moveDist = this->context->getYSpeed() * elapsedTime;

	this->context->setY(this->context->getY() - moveDist );
	distTravelled += moveDist;
	
	this->context->setShapePosition(this->context->getX(), this->context->getY());
	this->context->setSpritePosition(this->context->getX(), this->context->getY());

	//cout << "Bullet position at end of frame is " << this->context->getX() << ", " << this->context->getY() << endl;

	//if (this->distTravelled >= this->range) {
	if(this->context->getY() <= 0) {
		GameObjectManager* gm = GameObjectManager::getInstance();
		this->distTravelled = 0.0f;
		gm->erase(this->context->getId());

	}

}