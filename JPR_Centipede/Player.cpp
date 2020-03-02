#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(float initX, float initY) : GameObject(initX, initY) {

	this->xSpeed = 8.0f;
	this->ySpeed = 8.0f;
	this->shape.setRadius(0.5f);
	this->shape.setOutlineColor(Color::White);
	this->shape.setOutlineThickness(0.1f);
	this->shape.setFillColor(Color::Green);
	this->type = ObjectType::Player;

}

Player::Player(const Player& obj) : GameObject(obj) {}

Player::~Player() {}

Player& Player::operator=(const Player& obj) {

	return *this;

}
