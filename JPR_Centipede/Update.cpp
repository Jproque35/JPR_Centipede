#include "Engine.h"
#include "MovingObject.h"

void Engine::update(float dtAsSeconds) {

	/*
	for (int i = 0; i < enemies->size(); i++) {

		GameObject* currObject = this->enemies->get(i);

		if (currObject->isActive()) {
			currObject->checkCollision(this->bullet);

			for (int i = 0; i < obstacles->size(); i++) {

				//currObject->checkCollision(this->obstacles->get(i));

			}

			currObject->checkCollision(&window);

			currObject->update(dtAsSeconds);
		}

	}*/

	if (this->bullet->isActive()) {

		this->bullet->update(dtAsSeconds);

	}

	this->player->update(dtAsSeconds);
}