#include "GameScreen.h"
#include "EventManager.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "GameObjectState.h"
#include "CollisionMap.h"
#include "CentipedeManager.h"
#include "Centipede.h"

void GameScreen::update(float dtAsSeconds) {
	float initX = round(this->gridWidth / 2);
	float initY = 0.0f;

	if (this->cm->get(initX, initY).size() == 0
		&& this->centiMngr->getNumActive() <= 0) {

		vector<Centipede*> centipedes = this->centiMngr->generateCentipede(10);

		for (int i = 0; i < centipedes.size(); ++i) {

			this->gm->add(centipedes[i]);
			centipedes[i]->init(initX, initY);

		}

		cout << "Spawning new centipede" << endl;

	}

	//cout << "Updating objects..." << endl;
	this->em->update(dtAsSeconds);
	this->executeObjectEventListeners(dtAsSeconds);
	this->gm->updateAll(dtAsSeconds);
	this->cm->clear();
	this->cm->buildMap();

}

void GameScreen::executeObjectEventListeners(float elapsedTime) {

	for (int i = 0; i < this->gm->size(); i++) {

		if (this->gm->get(i) != NULL) {

			this->gm->get(i)->getState()->executeEventListeners(elapsedTime);

		}

	}

}