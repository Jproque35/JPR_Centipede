#include "Engine.h"

void Engine::input(float dtAsSeconds) {

	this->lastFiredTime += dtAsSeconds;

	if (Keyboard::isKeyPressed(Keyboard::Escape)) {

		this->window.close();

	}

	PlayerController* playerController = (PlayerController*)(this->objs->get(0));

	if (Keyboard::isKeyPressed(Keyboard::W)) {

		playerController->setKey(Keyboard::W);

	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {

		playerController->setKey(Keyboard::S);

	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {

		playerController->setKey(Keyboard::A);

	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {

		playerController->setKey(Keyboard::D);

	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {

		float gunX = this->objs->get(0)->getData()->getPosition().x + this->objs->get(0)->getData()->getShape().getRadius()
			- this->objs->get(1)->getData()->getShape().getRadius();

		float gunY = this->objs->get(0)->getData()->getPosition().y;

		if (this->loadedBullets.size() > 0) {

			PlayerBulletController* currBullet = this->loadedBullets.front();
			if (!currBullet->getData()->isActive()) {

				cout << "Fired object " << currBullet << endl;
				currBullet->setKey(Keyboard::Space, gunX, gunY);
				this->loadedBullets.pop();
				this->loadedBullets.push(currBullet);

			}

		}

	}

}