#include "Player.h"

Player::Player(float initX, float initY) : GameObject(initX, initY) {

	this->xSpeed = 400.0f;
	this->ySpeed = 400.0f;
	this->shape.setSize(Vector2f(50.0f, 50.0f));
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

void Player::checkCollision(GameObject* objs[]) {



}

void Player::checkCollision(GameObject* obj) {



}

void Player::checkCollision(Window* w) {



}

void Player::update(float elapsedTime) {

	if (this->upPressed) {

		this->position.y -= this->ySpeed * elapsedTime;

	}

	if (this->downPressed) {

		this->position.y += this->ySpeed * elapsedTime;

	}

	if (this->leftPressed) {

		this->position.x -= this->xSpeed * elapsedTime;

	}

	if (this->rightPressed) {

		this->position.x += this->xSpeed * elapsedTime;

	}

	this->shape.setPosition(this->position);

}
