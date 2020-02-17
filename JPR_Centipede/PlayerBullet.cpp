#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float initX, float initY) : ObjectData(initX, initY) {

	this->ySpeed = 750.0f;
	this->shape.setSize(Vector2f(5.0f, 30.0f));
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

void PlayerBullet::checkCollision(ObjectData* objs[]) {



}

void PlayerBullet::checkCollision(ObjectData* obj) {



}

void PlayerBullet::checkCollision(Window* w) {



}

void PlayerBullet::update(float elapsedTime) {

	if (this->active) {

		this->position.y -= this->ySpeed * elapsedTime;
		this->distanceTravelled += this->ySpeed * elapsedTime;
		this->shape.setPosition(position);

		if (this->distanceTravelled > 400.0f) {

			this->active = false;
			this->distanceTravelled = 0.0f;

		}

	}

}