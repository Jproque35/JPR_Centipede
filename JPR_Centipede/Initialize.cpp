#include "Engine.h"

void Engine::init() {

	int xRes = this->window.getSize().x;
	int yRes = this->window.getSize().y;
	this->objs = new GameObjectManager(23);
	this->grid = new GridManager(this->gridWidth, this->gridHeight);

	this->objs->add(0, new Player(0, floor(this->gridWidth / 2), this->gridHeight / 2));
	this->objs->get(0)->activate();
	this->objs->add(1, new PlayerBullet(0, 0, 0));
	this->playerController = new PlayerController((Player*)this->objs->get(0));
	this->bulletController = new PlayerBulletController((PlayerBullet*)this->objs->get(1));

	for (int i = 2; i < 3; i++) {

		this->objs->add(i, new Centipede(i, this->gridWidth/2, 0.0f));
		this->objs->get(i)->activate();
		this->testController = new CentipedeController((Centipede*)this->objs->get(i));

	}

	srand(time(NULL));

	for (int i = 3; i < 23; i++) {

		this->objs->add(i, new Mushroom(i, rand() % (int)(this->gridWidth - 1.0f), rand() % (int)(this->gridHeight - 1.0f) + 1));
		this->objs->get(i)->activate();

	}

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