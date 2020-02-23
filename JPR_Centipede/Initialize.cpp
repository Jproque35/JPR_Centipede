#include "Engine.h"

inline int Engine::getNumObjects() {

	return 1 + this->numBullets + this->numCentipedes + this->numMushrooms;

}

void Engine::init() {

	int xRes = this->window.getSize().x;
	int yRes = this->window.getSize().y;
	int currPos = 0;
	this->objs = new GameObjectManager(this->getNumObjects());
	this->objectControllers.resize(this->getNumObjects());
	this->grid = new GridManager(this->gridWidth, this->gridHeight);

	this->objs->add(0, new Player(floor(this->gridWidth / 2), floor(this->gridHeight / 2)));
	this->objs->get(0)->activate();
	this->objectControllers[0] = new PlayerController((Player*)this->objs->get(0));
	bulletsStart = ++currPos;

	int endPos = currPos + this->numBullets;
	cout << "Loading bullet objects..." << endl;

	while(currPos < endPos) {

		this->objs->add(currPos, new PlayerBullet(-1, -1));
		this->objectControllers[currPos] = new PlayerBulletController((PlayerBullet*)this->objs->get(currPos));
		this->loadedBullets.push((PlayerBulletController*)(this->objectControllers[currPos]));
		cout << "Loaded bullet object into slot " << currPos << endl;
		currPos++;

	}

	endPos = currPos + this->numCentipedes;
	cout << "Loading centipede objects..." << endl;

	while (currPos < endPos) {

		this->objs->add(currPos, new Centipede(this->gridWidth / 2, 0.0f));
		this->objectControllers[currPos] = new CentipedeController((Centipede*)this->objs->get(currPos), this->grid);
		this->objs->get(currPos)->activate();
		cout << "Loaded centipede object into slot " << currPos << endl;
		currPos++;

	}

	srand(time(NULL));

	endPos = currPos + this->numMushrooms;
	cout << "Loading mushroom objects..." << endl;

	while (currPos < endPos) {

		this->objs->add(currPos, new Mushroom(rand() % (int)(this->gridWidth - 1.0f), rand() % (int)(this->gridHeight - 1.0f) + 1));
		this->objectControllers[currPos] = new MushroomController((Mushroom*)this->objs->get(currPos));
		this->objs->get(currPos)->activate();
		cout << "Loaded mushroom object into slot " << currPos << endl;
		currPos++;

	}

	cout << "Successfully loaded all objects." << endl;

	this->buildGridState();

}

void Engine::buildGridState() {

	this->grid->clear();
	for (int i = 0; i < this->objs->size(); i++) {

		GameObject* currObj = this->objs->get(i);
		this->grid->add(currObj, floor(currObj->getPosition().x), floor(currObj->getPosition().y));
		
		/*
		cout << "(" << i << ") " << "Added object with address " << currObj 
			<< " to grid at position " << currObj->getPosition().x << ", " 
			<< currObj->getPosition().y << endl;
		*/
	}

}