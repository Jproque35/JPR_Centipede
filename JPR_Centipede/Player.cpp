#include "Player.h"

Player::Player(float initX, float initY) {

	this->context = new PlayerData(initX, initY);

}

Player::Player(const Player& obj) {

	this->context = obj.context;
	this->commands = obj.commands;

}

Player::~Player() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

ObjectData* Player::getData() {

	return this->context;

}

void Player::setKey(Keyboard::Key key) {

	this->key = key;

}

void Player::updateSub(float elapsedTime) {

}

void Player::collisionSub(ObjectData* obj) {



}