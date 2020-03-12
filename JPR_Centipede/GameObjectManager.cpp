#include "GameObjectManager.h"

GameObjectManager* GameObjectManager::instance = 0;

GameObjectManager::GameObjectManager(const GameObjectManager& obj) {

	this->gm = obj.gm;
	this->grid = obj.grid;

}

GameObjectManager::~GameObjectManager() {

	for (int i = 0; i < this->gm.size(); i++) {

		if (this->gm[i] != NULL) {

			delete(this->gm[i]);
			this->gm[i] = NULL;

		}

	}

	delete(this->grid);

}

GameObjectManager& GameObjectManager::operator=(const GameObjectManager& obj) {

	return *this;

}

GameObjectManager* GameObjectManager::getInstance() {

	if (!instance) {

		instance = new GameObjectManager();

	}

	return instance;

}

void GameObjectManager::resetInstance() {

	delete(instance);
	instance = NULL;

}

void GameObjectManager::init(int size, int x, int y) {

	this->gm.resize(size);

	for (int i = 0; i < this->gm.size(); i++) {

		this->gm[i] = NULL;

	}

	this->grid = new GridManager(x, y);

}

int GameObjectManager::getGridWidth() {

	return this->grid->getWidth();

}

int GameObjectManager::getGridHeight() {

	return this->grid->getHeight();

}

void GameObjectManager::rebuildGrid() {

	this->grid->clear();

	for (int i = 0; i < this->gm.size(); i++) {

		GameObject* currObj = this->gm[i];
		this->grid->add(currObj);

	}

}

void GameObjectManager::add(int i, GameObject* obj) {

	if (i < this->gm.size() && i >= 0) {

		this->gm[i] = obj;

	}

	this->grid->add(obj);

}

void GameObjectManager::update(int i, float elapsedTime) {

	if (this->gm[i] != NULL) {
		this->gm[i]->update(elapsedTime);
		this->rebuildGrid();
	}

}

void GameObjectManager::updateAll(float elapsedTime) {

	for (int i = 0; i < gm.size(); i++) {

		if (this->gm[i] != NULL) {
			this->gm[i]->update(elapsedTime);
		}

	}

	this->rebuildGrid();

}

vector<GameObject*> GameObjectManager::get(int x, int y) {

	return this->grid->get(x, y);

}

GameObject* GameObjectManager::get(int i) {

	return this->gm[i];

}

bool GameObjectManager::hasType(ObjectType type, int x, int y) {

	return this->grid->hasType(type, x, y);

}

void GameObjectManager::erase(int i) {

	if (this->gm[i] != NULL) {

		delete(this->gm[i]);
		this->gm[i] = NULL;

	}

	this->rebuildGrid();

}

int GameObjectManager::size() {

	return this->gm.size();

}