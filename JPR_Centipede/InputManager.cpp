#include "InputManager.h"

bool InputManager::isUpPressed() {

	return this->upPressed;

}

void InputManager::checkUpPressed() {

	if (Keyboard::isKeyPressed(this->upKey)) {

		this->upPressed = true;

	}
	else {

		this->upPressed = false;

	}

}

bool InputManager::isDownPressed() {

	return this->downPressed;

}

void InputManager::checkDownPressed() {

	if (Keyboard::isKeyPressed(this->downKey)) {

		this->downPressed = true;

	}
	else {

		this->downPressed = false;

	}

}

bool InputManager::isLeftPressed() {

	return this->leftPressed;

}

void InputManager::checkLeftPressed() {

	if (Keyboard::isKeyPressed(this->leftKey)) {

		this->leftPressed = true;

	}
	else {

		this->leftPressed = false;

	}

}

bool InputManager::isRightPressed() {

	return this->rightPressed;

}

void InputManager::checkRightPressed() {

	if (Keyboard::isKeyPressed(this->rightKey)) {

		this->rightPressed = true;

	}
	else {

		this->rightPressed = false;

	}

}
bool InputManager::isFirePressed() {

	return this->firePressed;

}

void InputManager::checkFirePressed() {

	if (Keyboard::isKeyPressed(this->fireKey)) {

		this->firePressed = true;

	}
	else {

		this->firePressed = false;

	}

}

void InputManager::update() {

	this->checkLeftPressed();
	this->checkDownPressed();
	this->checkUpPressed();
	this->checkRightPressed();
	this->checkFirePressed();

}

