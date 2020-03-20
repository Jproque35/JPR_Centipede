#include "Player.h"
#include "PlayerNormalState.h"

Player::Player() {

	this->type = ObjectType::Player;
	this->shape.setFillColor(Color::Green);
	
	PlayerNormalState* newState = new PlayerNormalState(this);
	this->currState = newState;

	this->states[newState->getType()] = newState;

}

Player::Player(const Player& obj) {


}

Player::~Player() {}

Player& Player::operator=(const Player& obj)
{

	GameObject::assignmentAux(obj);
	this->currState = obj.currState;
	return *this;

}

void Player::init(float xPos, float yPos) {

	this->pos.x = xPos;
	this->pos.y = yPos;
	this->xSpeed = 20.0f;
	this->ySpeed = 20.0f;
	this->shape.setPosition(this->pos);

}