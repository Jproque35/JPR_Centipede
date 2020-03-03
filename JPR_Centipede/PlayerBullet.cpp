#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float initX, float initY) {

	this->context = new PlayerBulletData(initX, initY);

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

void PlayerBullet::updateSub(float elapsedTime) {

	/*
	if (this->commands.size() < 1) {
		if (this->key == Keyboard::Space) {

			this->commands.push(new PlayerBulletFireCommand(this->context, this->xPos, this->yPos));

		}

		this->key = Keyboard::Unknown;

	}*/

}

void PlayerBullet::collisionSub(ObjectData* obj) {

	if (this->context != obj) {

		float diameter0 = this->context->getShape().getRadius() * 2;
		float diameter1 = obj->getShape().getRadius() * 2;

		if (this->context->getPosition().y + diameter0 >= obj->getPosition().y ||
			this->context->getPosition().y <= obj->getPosition().y + diameter1) {

			if (this->context->getPosition().x + diameter0 >= obj->getPosition().x ||
				this->context->getPosition().x <= obj->getPosition().x + diameter1) {

				cout << "Projectile hit something" << endl;


			}

		}

	}

}