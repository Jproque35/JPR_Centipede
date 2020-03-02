#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float initX, float initY) : GameObject(initX, initY) {

	this->ySpeed = 20.0f;
	this->shape.setRadius(0.2f);
	this->shape.setFillColor(Color::Yellow);
	this->type = ObjectType::PlayerProjectile;

}

PlayerBullet::PlayerBullet(const PlayerBullet& obj) : GameObject(obj) {}

PlayerBullet::~PlayerBullet() {}

PlayerBullet& PlayerBullet::operator=(const PlayerBullet& obj) {

	return *this;

}