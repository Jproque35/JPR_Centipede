#include "Engine.h"

void Engine::update(float dtAsSeconds) {

	this->testController->checkCollision(this->gridWidth, this->gridHeight);
	this->testController->update(dtAsSeconds);

	/*
	for (int i = 0; i < enemies->size(); i++) {

		GameObject* currObject = this->enemies->get(i);

		if (currObject->isActive()) {

			if(currObject->getCommandQueueSize() == 0) {
			}

			currObject->checkCollision(this->bullet);
			currObject->checkCollision(this->gridWidth, this->gridHeight);

			for (int i = 0; i < this->obstacles->size(); i++) {

				currObject->checkCollision(this->obstacles->get(i));

			}

			currObject->update(dtAsSeconds);
		}

	}*/

	if (this->bullet->isActive()) {

		this->bullet->update(dtAsSeconds);

	}

	this->player->update(dtAsSeconds);
}