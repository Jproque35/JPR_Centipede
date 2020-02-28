#include "PlayerBulletController.h"

PlayerBulletController::PlayerBulletController(PlayerBullet* context) {

	this->context = context;

}

PlayerBulletController::~PlayerBulletController() {

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

GameObject* PlayerBulletController::getData() {

	return this->context;

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

void PlayerBulletController::collisionSub(GameObject* obj) {

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

/*
void PlayerBulletController::handleFinishedCommand(ObjectCommand* command) {

	if (command != NULL) {

		delete(command);
		command = NULL;

	}

}*/