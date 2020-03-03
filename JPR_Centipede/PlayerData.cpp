#include "PlayerData.h"
#include <iostream>

using namespace std;

PlayerData::PlayerData(float initX, float initY) : ObjectData(initX, initY) {

	this->xSpeed = 8.0f;
	this->ySpeed = 8.0f;
	this->shape.setRadius(0.5f);
	this->shape.setOutlineColor(Color::White);
	this->shape.setOutlineThickness(0.1f);
	this->shape.setFillColor(Color::Green);
	this->type = ObjectType::PlayerData;

}

PlayerData::PlayerData(const PlayerData& obj) : ObjectData(obj) {}

PlayerData::~PlayerData() {}

PlayerData& PlayerData::operator=(const PlayerData& obj) {

	return *this;

}
