#include "Player.h"
#include "PlayerNormalState.h"

Player::Player() {

	this->type = ObjectType::Player;
	this->shape.setFillColor(Color::Green);
	
	PlayerNormalState* newState = new PlayerNormalState(this);
	this->currState = newState;

	this->states[newState->getType()] = newState;

}


Player::~Player() {

	cout << "Destructing Player object..." << endl;

}

void Player::init(float xPos, float yPos) {

	this->pos.x = xPos;
	this->pos.y = yPos;
	this->xSpeed = 20.0f;
	this->ySpeed = 20.0f;
	this->shape.setPosition(this->pos);

}