#include "Engine.h"

void Engine::init() {

	int xRes = this->window.getSize().x;
	int yRes = this->window.getSize().y;

	this->player = new Player(floor(this->gridWidth / 2), this->gridHeight/2);
	this->bullet = new PlayerBullet(xRes / 2, yRes / 2);
	this->playerController = new PlayerController(this->player);
	
	this->enemies = new GameObjectManager(1);
	this->obstacles = new GameObjectManager(30);

	for (int i = 0; i < this->enemies->size(); i++) {

		this->enemies->add(i, new Centipede(this->gridWidth/2, 0.0f));
		this->enemies->get(i)->activate();
		this->testController = new CentipedeController((Centipede*)this->enemies->get(i));

	}

	srand(time(NULL));

	for (int i = 0; i < this->obstacles->size(); i++) {

		this->obstacles->add(i, new Mushroom(rand() % (int)(floor(this->gridWidth)) + 1, rand() % (int)(floor(this->gridHeight)) + 1));

	}

}