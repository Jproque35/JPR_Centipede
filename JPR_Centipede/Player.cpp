#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(int id, float initX, float initY) : GameObject(id, initX, initY) {

	this->xSpeed = 8.0f;
	this->ySpeed = 8.0f;
	this->shape.setRadius(0.5);
	this->shape.setOutlineColor(Color::White);
	this->shape.setOutlineThickness(0.1);
	this->shape.setFillColor(Color::Green);
	this->type = ObjectType::Player;

}
