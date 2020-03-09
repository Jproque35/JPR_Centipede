#include "PlayerBulletData.h"

PlayerBulletData::PlayerBulletData(float initX, float initY) : ObjectData(initX, initY) {

	this->ySpeed = 20.0f;
	this->shape.setRadius(0.2f);
	this->shape.setFillColor(Color::Yellow);
	this->type = ObjectType::PlayerProjectile;

}

PlayerBulletData::PlayerBulletData(const PlayerBulletData& obj) : ObjectData(obj) {}

PlayerBulletData::~PlayerBulletData() {}

PlayerBulletData& PlayerBulletData::operator=(const PlayerBulletData& obj) {

	return *this;

}