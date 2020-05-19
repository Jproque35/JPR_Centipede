#include "GameScreen.h"
#include "EventManager.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "GameObjectState.h"
#include "CollisionMap.h"
#include "CentipedeManager.h"
#include "Centipede.h"
#include "EngineConstants.h"

void GameScreen::update(float dtAsSeconds) {
	GameObjectManager* gm = GameObjectManager::getInstance();
	EventManager* em = EventManager::getInstance();
	CollisionMap* cm = CollisionMap::getInstance();
	CentipedeManager* centiMngr = CentipedeManager::getInstance();

	float initX = round(EngineConstants::getMapWidth() / 2);
	float initY = 0.0f;

	if (cm->get(initX, initY).size() == 0
		&& centiMngr->getNumActive() <= 0) {

		vector<Centipede*> centipedes = centiMngr->generateCentipede(10);

		for (int i = 0; i < centipedes.size(); ++i) {

			gm->add(centipedes[i]);
			centipedes[i]->init(initX, initY);

		}

		cout << "Spawning new centipede" << endl;

	}

	//cout << "Updating objects..." << endl;

	cm->clear();
	cm->buildMap();
	em->update(dtAsSeconds);
	executeObjectEventListeners(dtAsSeconds);
	gm->updateAll(dtAsSeconds);

}

void GameScreen::executeObjectEventListeners(float elapsedTime) {

	GameObjectManager* gm = GameObjectManager::getInstance();

	for (int i = 0; i < gm->size(); i++) {

		if (gm->get(i) != NULL) {

			gm->get(i)->getState()->executeEventListeners(elapsedTime);

		}

	}

}