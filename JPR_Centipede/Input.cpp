#include "Engine.h"

void Engine::input() {

	if (Keyboard::isKeyPressed(Keyboard::Escape)) {

		this->window.close();

	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {

		this->player->moveUp();

	}
	else {

		this->player->stopUp();

	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {

		this->player->moveDown();

	}
	else {

		this->player->stopDown();

	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {

		this->player->moveLeft();

	}
	else {

		this->player->stopLeft();

	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {

		this->player->moveRight();

	}
	else {

		this->player->stopRight();

	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && !this->bullet->isActive()) {

		float gunX = this->player->getPosition().x + this->player->getShape().getRadius();

		this->bullet->setPosition(gunX, this->player->getPosition().y);
		cout << "Bullet position is " << this->bullet->getPosition().x << ", " << this->bullet->getPosition().y << endl;
		this->bullet->activate();

	}

}