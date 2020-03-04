#include "Engine.h"
#include "CentipedeMoveEvent.h"
#include "PlayerInputEvent.h"
#include "BulletFiredEvent.h"
#include "MushroomHitEvent.h"
#include "CentipedeHitEvent.h"
#include "BulletCollideEvent.h"

inline int Engine::getNumObjects() {

	return 1 + this->numBullets + this->numCentipedes + this->numMushrooms;

}

void Engine::init() {
	int xRes = this->window.getSize().x;
	int yRes = this->window.getSize().y;
	this->gm = new GameObjectManager(this->getNumObjects(), this->gridWidth, this->gridHeight);
	this->em = new EventManager(this->gm);

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
	ObjectData* newObj;

	this->gm->add(0, new Player( floor(this->gridWidth/2), floor(this->gridHeight/2) ));
	this->gm->get(0)->addEventListener(new PlayerInputEvent(this->gm, 0));
	this->gm->get(0)->getData()->activate();
	bulletsStart = ++currPos;

	int endPos = currPos + this->numBullets;
	cout << "Loading bullet objects..." << endl;

	while (currPos < endPos) {

		this->gm->add(currPos, new PlayerBullet(-1, -1));
		this->gm->get(currPos)->addEventListener(new BulletFiredEvent(this->gm, currPos));
		this->gm->get(currPos)->addEventListener(new BulletCollideEvent(this->gm, currPos));
		this->loadedBullets.push((PlayerBullet*)(this->gm->get(currPos)));
		cout << "Loaded bullet object into slot " << currPos << endl;
		currPos++;

	}
}

void Engine::initEnemies(int &currPos) {

	int initPos = currPos;
	int endPos = currPos + this->numCentipedes;
	cout << "Loading centipede objects..." << endl;

	while (currPos < endPos) {

		this->gm->add(currPos, new Centipede(this->gridWidth / 2, 0.0f));
		this->em->addEvent(new CentipedeMoveEvent(this->gm, currPos));
		this->em->addEvent(new CentipedeHitEvent(this->gm, currPos));
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

		int tempX = rand() % (int)(this->gridWidth - 1.0f);
		int tempY = rand() % (int)(this->gridHeight - 1.0f) + 1;

		this->gm->add(currPos, new Mushroom(tempX, tempY));
		this->gm->get(currPos)->getData()->activate();
		this->gm->get(currPos)->addEventListener(new MushroomHitEvent(this->gm, currPos));
		cout << "Loaded mushroom object into slot " << currPos << " at position " << tempX << ", " << tempY << endl;
		currPos++;

	}

}

void Engine::initEvents() {

	cout << "Loading game events.." << endl;

	cout << "Successfully loaded all game events." << endl;

}