#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(float initX, float initY) : GameObject(initX, initY) {

	this->xSpeed = 8.0f;
	this->ySpeed = 8.0f;
	this->shape.setSize(Vector2f(1.0f, 1.0f));
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

	if (this->upPressed) {

		this->position.y -= this->ySpeed * elapsedTime;
		cout << "Position is " << this->position.x << ", " << this->position.y << endl;

	}

	if (this->downPressed) {

		this->position.y += this->ySpeed * elapsedTime;
		cout << "Position is " << this->position.x << ", " << this->position.y << endl;

	}

	if (this->leftPressed) {

		this->position.x -= this->xSpeed * elapsedTime;
		cout << "Position is " << this->position.x << ", " << this->position.y << endl;

	}

	if (this->rightPressed) {

		this->position.x += this->xSpeed * elapsedTime;
		cout << "Position is " << this->position.x << ", " << this->position.y << endl;

	}

	this->shape.setPosition(this->position);

}
