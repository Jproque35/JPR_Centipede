#include "InputManager.h"

InputManager* InputManager::instance = 0;

InputManager::~InputManager() {};

InputManager* InputManager::getInstance() {

	if (!instance) {

		instance = new InputManager();

	}

	return instance;

}

void InputManager::resetInstance() {

	delete(instance);
	instance = NULL;

}

bool InputManager::isUpPressed() {

	return this->upActive;

}

void InputManager::upPressed() {

	if (Keyboard::isKeyPressed(this->upKey)) {

		this->upActive = true;

	}
	else {

		this->upActive = false;

	}

}

bool InputManager::isDownPressed() {

	return this->downActive;

}

void InputManager::downPressed() {

	if (Keyboard::isKeyPressed(this->downKey)) {

		this->downActive = true;

	}
	else {

		this->downActive = false;

	}

}

bool InputManager::isLeftPressed() {

	return this->leftActive;

}

void InputManager::leftPressed() {

	if (Keyboard::isKeyPressed(this->leftKey)) {

		this->leftActive = true;

	}
	else {

		this->leftActive = false;

	}

}

bool InputManager::isRightPressed() {

	return this->rightActive;

}

void InputManager::rightPressed() {

	if (Keyboard::isKeyPressed(this->rightKey)) {

		this->rightActive = true;

	}
	else {

		this->rightActive = false;

	}

}
bool InputManager::isFirePressed() {

	return this->fireActive;

}

void InputManager::firePressed() {

	if (Keyboard::isKeyPressed(this->fireKey)) {

		this->fireActive = true;

	}
	else {

		this->fireActive = false;

	}

}

bool InputManager::isDebugActive() {

	return this->debugActive;

}

void InputManager::debugPressed() {

	if (Keyboard::isKeyPressed(this->debugKey)) {

		if (!this->debugActive && !this->debugLock) {

			this->debugActive = true; 

		}
		else if(this->debugActive && !this->debugLock) {

			this->debugActive = false;

		}

		this->debugLock = true;

	}
	else {

		this->debugLock = false;

	}

}

void InputManager::update() {

	this->leftPressed();
	this->downPressed();
	this->upPressed();
	this->rightPressed();
	this->firePressed();
	this->debugPressed();

}

