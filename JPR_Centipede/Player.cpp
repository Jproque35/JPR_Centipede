#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(float initX, float initY) : GameObject(initX, initY) {

	this->xSpeed = 8.0f;
	this->ySpeed = 8.0f;
	this->shape.setRadius(0.5);
	this->shape.setFillColor(Color::Green);
	this->type = ObjectType::Player;

}
