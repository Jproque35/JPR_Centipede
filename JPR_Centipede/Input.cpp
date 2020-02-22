#include "Engine.h"

void Engine::input() {

	if (Keyboard::isKeyPressed(Keyboard::Escape)) {

		this->window.close();

	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {

		this->playerController->setKey(Keyboard::W);

	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {

		this->playerController->setKey(Keyboard::S);

	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {

		this->playerController->setKey(Keyboard::A);

	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {

		this->playerController->setKey(Keyboard::D);

	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && !this->objs->get(1)->isActive()) {

		float gunX = this->objs->get(0)->getPosition().x + this->objs->get(0)->getShape().getRadius()
			- this->objs->get(1)->getShape().getRadius();

		float gunY = this->objs->get(0)->getPosition().y;

		this->bulletController->setKey(Keyboard::Space, gunX, gunY);

	}

}