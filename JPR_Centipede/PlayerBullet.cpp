#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(int id, float initX, float initY) : GameObject(id, initX, initY) {

	this->ySpeed = 20.0f;
	this->shape.setRadius(0.2);
	this->shape.setFillColor(Color::Yellow);
	this->type = ObjectType::PlayerProjectile;

}