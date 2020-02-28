#include "Engine.h"
#include "CentipedeMoveEvent.h"
#include "PlayerInputEvent.h"
#include "BulletFiredEvent.h"

inline int Engine::getNumObjects() {

	return 1 + this->numBullets + this->numCentipedes + this->numMushrooms;

}

void Engine::init() {
	int xRes = this->window.getSize().x;
	int yRes = this->window.getSize().y;
	this->objs = new GameObjectManager(this->getNumObjects(), this->gridWidth, this->gridHeight);
	this->em = new EventManager(this->objs);

	this->initObjects();
	this->initEvents();

}

void Engine::initObjects() {

	int currPos = 0;
	GameObject* newObj = new Player(floor(this->gridWidth / 2), floor(this->gridHeight / 2));

	this->objs->add(0,  new PlayerController((Player*)newObj));
	this->em->addEvent(new PlayerInputEvent(this->objs, 0));
	this->objs->get(0)->getData()->activate();
	bulletsStart = ++currPos;

	int endPos = currPos + this->numBullets;
	cout << "Loading bullet objects..." << endl;

	while(currPos < endPos) {

		newObj = new PlayerBullet(-1, -1);
		this->objs->add(currPos, new PlayerBulletController((PlayerBullet*)newObj));
		this->em->addEvent(new BulletFiredEvent(this->objs, currPos));
		this->loadedBullets.push((PlayerBulletController*)(this->objs->get(currPos)));
		cout << "Loaded bullet object into slot " << currPos << endl;
		currPos++;

	}

	endPos = currPos + this->numCentipedes;
	cout << "Loading centipede objects..." << endl;

	while (currPos < endPos) {

		newObj = new Centipede(this->gridWidth / 2, 0.0f);
		this->objs->add(currPos, new CentipedeController((Centipede*)newObj));
		this->objs->get(currPos)->getData()->activate();
		this->em->addEvent(new CentipedeMoveEvent(this->objs, currPos));
		cout << "Loaded centipede object into slot " << currPos << endl;
		currPos++;

	}

	srand(time(NULL));

	endPos = currPos + this->numMushrooms;
	cout << "Loading mushroom objects..." << endl;

	while (currPos < endPos) {

		int tempX = rand() % (int)(this->gridWidth - 1.0f);
		int tempY = rand() % (int)(this->gridHeight - 1.0f) + 1;

		newObj = new Mushroom(tempX, tempY);
		this->objs->add(currPos, new MushroomController((Mushroom*)newObj));
		this->objs->get(currPos)->getData()->activate();
		cout << "Loaded mushroom object into slot " << currPos << " at position " << tempX << ", " << tempY << endl;
		currPos++;

	}

	cout << "Successfully loaded all objects." << endl;

}

void Engine::initEvents() {

	cout << "Loading game events.." << endl;

	cout << "Successfully loaded all game events." << endl;

}