#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float initX, float initY) : GameObject(initX, initY) {

	this->ySpeed = 20.0f;
	this->shape.setSize(Vector2f(0.1f, 1.0f));
	this->shape.setFillColor(Color::Yellow);
	this->type = ObjectType::PlayerProjectile;

}

void PlayerBullet::setPosition(float x, float y) {

	this->position.y = y;
	this->position.x = x;

}

float PlayerBullet::getDistanceTravelled() {

	return this->distanceTravelled;

}

void PlayerBullet::checkCollision(GameObject* obj) {



}

void PlayerBullet::checkCollision(float xBoundary, float yBoundary) {



}

void PlayerBullet::update(float elapsedTime) {

	if (this->active) {

		this->position.y -= this->ySpeed * elapsedTime;
		this->distanceTravelled += this->ySpeed * elapsedTime;
		this->shape.setPosition(position);

		if (this->position.y < 0.0f) {

			this->active = false;
			this->distanceTravelled = 0.0f;

		}

	}

}