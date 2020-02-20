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

void Player::moveUp() {

	this->upPressed = true;

}

void Player::moveDown() {

	this->downPressed = true;

}

void Player::moveLeft() {

	this->leftPressed = true;

}

void Player::moveRight() {

	this->rightPressed = true;

}

void Player::stopUp() {

	this->upPressed = false;

}

void Player::stopDown() {

	this->downPressed = false;

}

void Player::stopLeft() {

	this->leftPressed = false;

}

void Player::stopRight() {

	this->rightPressed = false;

}

void Player::checkCollision(GameObject* obj) {



}

void Player::checkCollision(float xBoundary, float yBoundary) {



}

void Player::update(float elapsedTime) {

	if (this->commands.size() > 0) {

		ObjectCommand* currCommand = this->commands.front();

		currCommand->execute(elapsedTime);

		if (currCommand->isFinished()) {

			this->commands.pop();
			delete(currCommand);

		}
	}

	this->shape.setPosition(this->position);

}
