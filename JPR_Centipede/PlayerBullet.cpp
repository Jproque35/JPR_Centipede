#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float initX, float initY) {

	this->context = new PlayerBulletData(initX, initY);
	this->state = new GenericState();

}

PlayerBullet::PlayerBullet(const PlayerBullet& obj) {

	this->context = obj.context;
	this->commands = obj.commands;

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

void PlayerBullet::setKey(Keyboard::Key key, float x, float y) {

	this->xPos = x;
	this->yPos = y;
	this->key = key;

}

void PlayerBullet::preUpdate(float elapsedTime) {

}

void PlayerBullet::postUpdate(float elapsedTIme) {

	if (this->commands.size() == 0) {

		this->context->setPosition(Vector2f(-1.0f, -1.0f));
		this->context->getShape().setPosition(this->context->getPosition());

	}

}