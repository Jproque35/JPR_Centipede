#include "Engine.h"
#include "InputManager.h"

void Engine::input(float dtAsSeconds) {

	if (Keyboard::isKeyPressed(Keyboard::Escape)) {

		this->window.close();
		
	}

	this->im->update();

}