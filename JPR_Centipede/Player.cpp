#include "Player.h"

Player::Player(float initX, float initY) {

	this->context = new PlayerData(initX, initY);
	this->state = new GenericState();

}

Player::Player(const Player& obj) {

	this->context = obj.context;

}

Player::~Player() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

ObjectData* Player::getData() const {

	return this->context;

}

void Player::preUpdate(float elapsedTime) {

}

void Player::postUpdate(float elapsedTime) {

	

}