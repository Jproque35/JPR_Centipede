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

	if (Keyboard::isKeyPressed(Keyboard::Space) && !this->bullet->isActive()) {

		float gunX = this->player->getPosition().x + this->player->getShape().getRadius();

		this->bullet->setPosition(gunX, this->player->getPosition().y);
		cout << "Bullet position is " << this->bullet->getPosition().x << ", " << this->bullet->getPosition().y << endl;
		this->bullet->activate();

	}

}