#include "PlayerBulletController.h"

PlayerBulletController::PlayerBulletController(PlayerBullet* context) {

	this->context = context;

}

void PlayerBulletController::setKey(Keyboard::Key key, float x, float y) {

	this->xPos = x;
	this->yPos = y;
	this->key = key;

}

void PlayerBulletController::updateSub(float elapsedTime) {

	if (this->commands.size() < 1) {
		if (this->key == Keyboard::Space) {

			this->commands.push(new PlayerBulletFireCommand(this->context, this->xPos, this->yPos));

		}

		this->key = Keyboard::Unknown;

	}

}