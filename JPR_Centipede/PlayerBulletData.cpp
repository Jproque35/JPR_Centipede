#include "PlayerBulletData.h"

PlayerBulletData::PlayerBulletData(float initX, float initY) : ObjectData(initX, initY) {

	this->shape.setRadius(0.2f);
	this->shape.setFillColor(Color::Yellow);
	this->type = ObjectType::PlayerProjectile;

	/*
	this->img.loadFromFile("assets/sprites/player.png");
	this->spr.setTexture(this->img);
	*/
	
	this->init(initX, initY);

}

PlayerBulletData::PlayerBulletData(const PlayerBulletData& obj) : ObjectData(obj) {}

PlayerBulletData::~PlayerBulletData() {}

void PlayerBulletData::init(float xPos, float yPos) {

	this->position.x = xPos;
	this->position.y = yPos;
	this->ySpeed = 20.0f;

}

PlayerBulletData& PlayerBulletData::operator=(const PlayerBulletData& obj) {

	return *this;

}