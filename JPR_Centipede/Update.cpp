#include "Engine.h"

void Engine::update(float dtAsSeconds) {

	this->buildGridState();

	//this->testController->checkCollisionsWithObjects();
	this->testController->checkCollision(this->gridWidth, this->gridHeight, dtAsSeconds);
	this->testController->checkCollisionWithObjects(this->getCollisionObjects(this->testController->getData()));
	this->testController->update(dtAsSeconds);

	this->bulletController->update(dtAsSeconds);
	this->playerController->update(dtAsSeconds);
}

vector<vector<GameObject*>> Engine::getCollisionObjects(GameObject* obj) {

	int xLo = floor(obj->getPosition().x);
	int yLo = floor(obj->getPosition().y);
	float diameter = 2 * obj->getShape().getRadius();
	int xHi = floor(obj->getPosition().x + diameter);
	int yHi = floor(obj->getPosition().y + diameter);

	vector<vector<GameObject*>> desire;

	for (int i = xLo; i < xHi; i++) {

		for (int j = yLo; j < yHi; j++) {

			desire.push_back(this->grid->get(i, j));

		}
	}

	return desire;
}