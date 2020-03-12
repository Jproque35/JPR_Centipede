#include "Engine.h"

inline int Engine::getNumObjects() {

	return 1 + this->numBullets + this->numCentipedes + this->numMushrooms;

}

void Engine::init() {
	int xRes = this->window.getSize().x;
	int yRes = this->window.getSize().y;
	this->gm = GameObjectManager::getInstance();
	this->im = InputManager::getInstance();
	this->sm = ScoreManager::getInstance();
	this->em = new EventManager(this->gm);

	this->gm->init(this->getNumObjects(), this->gridWidth, this->gridHeight);

	this->initObjects();
	this->initEvents();

}

void Engine::initObjects() {

	int currPos = 0;

	this->initPlayer(currPos);
	this->initEnemies(currPos);
	this->initMushrooms(currPos);

	cout << "Successfully loaded all objects." << endl;

}

void Engine::initPlayer(int &currPos) {
	
	float initX = floor(this->gridWidth / 2);
	float initY = floor(this->gridHeight / 2);

	this->gm->add(0, GameObjectFactory::makeObject(ObjectType::PlayerData, initX, initY));
	this->gm->get(0)->getData()->activate();
	bulletsStart = ++currPos;

	int endPos = currPos + this->numBullets;
	cout << "Loading bullet objects..." << endl;

	while (currPos < endPos) {

		this->gm->add(currPos, GameObjectFactory::makeObject(ObjectType::PlayerProjectile, initX, initY));
		cout << "Loaded bullet object into slot " << currPos << endl;
		currPos++;

	}
}

void Engine::initEnemies(int &currPos) {

	int initPos = currPos;
	int endPos = currPos + this->numCentipedes;
	cout << "Loading centipede objects..." << endl;

	while (currPos < endPos) {

		float initX = floor(this->gridWidth / 2);
		float initY = 0.0f;

		this->gm->add(currPos, GameObjectFactory::makeObject(ObjectType::CentipedeData, initX, initY) );
		cout << "Loaded centipede object into slot " << currPos << endl;
		currPos++;

	}

	int currPos2 = initPos;

	while (currPos2 < endPos) {

		Centipede* currObj = (Centipede*)(this->gm->get(currPos2));

		if (currPos2 > initPos) {

			currObj->setPrev((Centipede*)(this->gm->get(currPos2 - 1)));

		}

		if (currPos2 < endPos - 1) {

			currObj->setNext((Centipede*)(this->gm->get(currPos2 + 1)));
			cout << "Next for " << currPos2 << " set to " << currPos2 + 1 << endl;

		}

		if (currPos2 > initPos && currPos2 < endPos) {

			currObj->setCentipedeType(CentipedeType::Body);

		}

		currPos2++;

	}


	this->gm->get(initPos)->getData()->activate();

}

void Engine::initMushrooms(int &currPos) {

	srand(time(NULL));

	int endPos = currPos + this->numMushrooms;
	cout << "Loading mushroom objects..." << endl;

	while (currPos < endPos) {

		float tempX = rand() % (int)(this->gridWidth);
		float tempY = rand() % (int)(this->gridHeight - 1.0f) + 1;

		Mushroom* newObj = new Mushroom(tempX, tempY);

		this->gm->add(currPos, GameObjectFactory::makeObject(ObjectType::MushroomData, tempX, tempY));
		this->gm->get(currPos)->getData()->activate();
		cout << "Loaded mushroom object into slot " << currPos << " at position " << tempX << ", " << tempY << endl;
		currPos++;

	}

}

void Engine::initEvents() {

	cout << "Loading game events.." << endl;

	cout << "Successfully loaded all game events." << endl;

}