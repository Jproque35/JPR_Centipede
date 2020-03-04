#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float initX, float initY) {

	this->context = new PlayerBulletData(initX, initY);
	this->state = new GenericState();

}

PlayerBullet::PlayerBullet(const PlayerBullet& obj) {

	this->context = obj.context;

}

PlayerBullet::~PlayerBullet() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

PlayerBullet& PlayerBullet::operator=(const PlayerBullet& obj) {

	return *this;

}

ObjectData* PlayerBullet::getData() {

	return this->context;

}

void PlayerBullet::preUpdate(float elapsedTime) {

}

void PlayerBullet::postUpdate(float elapsedTIme) {

	if (this->state->getCommandQueueSize() == 0) {

		this->context->setPosition(Vector2f(-1.0f, -1.0f));
		this->context->getShape().setPosition(this->context->getPosition());

	}

}