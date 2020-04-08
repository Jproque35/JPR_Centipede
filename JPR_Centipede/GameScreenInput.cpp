#include "GameScreen.h"
#include "InputManager.h"

void GameScreen::input(float dtAsSeconds) {

	/*
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {

		this->window.close();

	}*/

	this->im->update();

}