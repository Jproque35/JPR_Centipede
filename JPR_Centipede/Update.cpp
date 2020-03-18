#include "Engine.h"

void Engine::update(float dtAsSeconds) {

	//cout << "Updating objects..." << endl;
	this->em->update(dtAsSeconds);
	this->executeObjectEventListeners(dtAsSeconds);
	this->gm->updateAll(dtAsSeconds);

}

void Engine::executeObjectEventListeners(float elapsedTime) {

	for (int i = 0; i < this->gm->size(); i++) {

		if (this->gm->get(i) != NULL) {
			this->gm->get(i)->executeEventListeners(elapsedTime);
		}

	}

}