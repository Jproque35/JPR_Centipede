#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(float initX, float initY) {

	this->shape.setRadius(0.2f);
	this->shape.setFillColor(Color::Yellow);
	this->type = ObjectType::PlayerBullet;

}

PlayerBullet::PlayerBullet(const PlayerBullet& obj) {

	GameObject::assignmentAux(obj);

}

PlayerBullet::~PlayerBullet() {}

PlayerBullet& PlayerBullet::operator=(const PlayerBullet& obj) {

	return *this;

}

void PlayerBullet::init(float xPos, float yPos) {

	this->pos.x = xPos;
	this->pos.y = yPos;
	this->xSpeed = 0.0f;
	this->ySpeed = 20.0f;
	this->shape.setPosition(this->pos);

}

