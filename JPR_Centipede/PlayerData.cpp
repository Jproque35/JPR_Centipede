#include "PlayerData.h"
#include <iostream>

using namespace std;

PlayerData::PlayerData(float initX, float initY) : ObjectData(initX, initY) {

	this->shape.setRadius(0.5f);
	this->shape.setOutlineColor(Color::White);
	this->shape.setOutlineThickness(0.1f);
	this->shape.setFillColor(Color::Green);
	this->type = ObjectType::PlayerData;

	/*
	this->img.loadFromFile("assets/sprites/player.png");
	this->spr.setTexture(this->img);
	*/
	
	this->init(initX, initY);

}

PlayerData::PlayerData(const PlayerData& obj) : ObjectData(obj) {}

PlayerData::~PlayerData() {}

void PlayerData::init(float xPos, float yPos) {

	this->position.x = xPos;
	this->position.y = yPos;
	this->xSpeed = 8.0f;
	this->ySpeed = 8.0f;

}

PlayerData& PlayerData::operator=(const PlayerData& obj) {

	return *this;

}
