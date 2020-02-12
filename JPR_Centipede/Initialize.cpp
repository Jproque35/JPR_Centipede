#include "Engine.h"

void Engine::init() {

	int xRes = this->window.getSize().x;
	int yRes = this->window.getSize().y;

	this->player = new Player(xRes/ 2, yRes / 2);
	this->bullet = new PlayerBullet(xRes / 2, yRes / 2);
	this->enemies = new GameObjectManager(20);
	this->obstacles = new GameObjectManager(30);

	for (int i = 0; i < this->enemies->size(); i++) {

		this->enemies->add(i, new MovingObject(0.0f, 0.0f));

	}

	srand(time(NULL));

	for (int i = 0; i < this->obstacles->size(); i++) {

		this->obstacles->add(i, new DestroyableObject(rand() % (xRes - 50) + 50, rand() % (yRes - 50) + 50));

	}

}