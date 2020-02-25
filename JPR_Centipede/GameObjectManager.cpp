#include "GameObjectManager.h"

GameObjectManager::GameObjectManager(int size, int x, int y) {

	this->objs.resize(size);

	for (int i = 0; i < this->objs.size(); i++) {

		this->objs[i] = NULL;

	}

	this->grid = new GridManager(x, y);

}

GameObjectManager::~GameObjectManager() {

	for (int i = 0; i < this->objs.size(); i++) {

		if (this->objs[i] != NULL) {
			delete(this->objs[i]);
			this->objs[i] = NULL;
		}

	}

	delete(this->grid);

}

int GameObjectManager::getGridWidth() {

	return this->grid->getWidth();

}

int GameObjectManager::getGridHeight() {

	return this->grid->getHeight();

}

void GameObjectManager::rebuildGrid() {

	this->grid->clear();

	for (int i = 0; i < this->objs.size(); i++) {

		ObjectController* currObj = this->objs[i];
		this->grid->add(currObj);

	}

}

void GameObjectManager::add(int i, ObjectController* obj) {

	if (i < this->objs.size() && i >= 0) {

		this->objs[i] = obj;

	}

	this->grid->add(obj);

}

void GameObjectManager::update(int i, float elapsedTime) {

	if (this->objs[i] != NULL) {
		this->objs[i]->update(elapsedTime);
		this->rebuildGrid();
	}

}

void GameObjectManager::updateAll(float elapsedTime) {

	for (int i = 0; i < objs.size(); i++) {

		if (this->objs[i] != NULL) {
			this->objs[i]->update(elapsedTime);
		}

	}

	this->rebuildGrid();

}

vector<ObjectController*> GameObjectManager::get(int x, int y) {

	return this->grid->get(x, y);

}

ObjectController* GameObjectManager::get(int i) {

	return this->objs[i];

}

bool GameObjectManager::hasType(ObjectType type, int x, int y) {

	return this->grid->hasType(type, x, y);

}

void GameObjectManager::erase(int i) {

	if (this->objs[i] != NULL) {

		delete(this->objs[i]);
		this->objs[i] = NULL;

	}

	this->rebuildGrid();

}

int GameObjectManager::size() {

	return this->objs.size();

}