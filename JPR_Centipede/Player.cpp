#include "Player.h"

Player::Player() {

	this->type = ObjectType::Player;
	this->shape.setFillColor(Color::Green);

}

Player::Player(const Player& obj) {


}

Player::~Player() {

	GameObject::deleteStates();

}

Player& Player::operator=(const Player& obj)
{

	GameObject::assignmentAux(obj);
	this->currState = obj.currState;
	return *this;

}

void Player::init(float xPos, float yPos) {

	this->pos.x = xPos;
	this->pos.y = yPos;
	this->xSpeed = 8.0f;
	this->ySpeed = 8.0f;
	this->shape.setPosition(this->pos);

}