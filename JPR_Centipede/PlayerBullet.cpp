#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float initX, float initY) : GameObject(initX, initY) {

	this->ySpeed = 20.0f;
	this->shape.setRadius(0.1);
	this->shape.setFillColor(Color::Yellow);
	this->type = ObjectType::PlayerProjectile;

}