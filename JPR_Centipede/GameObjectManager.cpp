#include "GameObjectManager.h"
#include "GameObject.h"
#include "GridManager.h"

GameObjectManager* GameObjectManager::instance = 0;

GameObjectManager::GameObjectManager() {

	//this->objFactory = GameObjectFactory::getInstance();
	this->grid = NULL;

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

void GameObjectManager::init(int x, int y) {

	this->gm.resize(256);

	for (int i = 0; i < this->gm.size(); i++) {

		this->freeIds.push(i);
		this->gm[i] = NULL;

	}

	this->grid = new GridManager(x, y);

}

int GameObjectManager::getGridWidth() const {

	return this->grid->getWidth();

}

int GameObjectManager::getGridHeight() const {

	return this->grid->getHeight();

}

void GameObjectManager::rebuildGrid() {

	this->grid->clear();

	for (int i = 0; i < this->gm.size(); i++) {

		GameObject* currObj = this->gm[i];
		this->grid->add(currObj);

	}

}

void GameObjectManager::add(GameObject* obj) {

	int newPos = -1;

	if (this->freeIds.size() > 0) {

		newPos = this->freeIds.front();
		this->freeIds.pop();

	}

	if (newPos > -1 && obj != NULL) {

		obj->setId(newPos);
		this->gm[newPos] = obj;

	}
	else {

		cout << "There are no free slots." << endl;

	}

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

vector<GameObject*> GameObjectManager::get(int x, int y) const {

	return this->grid->get(x, y);

}

GameObject* GameObjectManager::get(int i) const {

	return this->gm[i];

}

bool GameObjectManager::hasType(ObjectType type, int x, int y) const {

	return this->grid->hasType(type, x, y);

}

void GameObjectManager::erase(int i) {

	if (this->gm[i] != NULL) {

		//delete(this->gm[i]);
		//this->objFactory->storeObject(this->gm[i]);
		this->freeIds.push(i);

		/*
		cout << "Free IDs: ";

		for (int i = 0; i < this->freeIds.size(); ++i) {

			int currId = this->freeIds.front();
			cout << currId << " ";
			this->freeIds.pop();
			this->freeIds.push(currId);

		}

		cout << endl;
		*/

		this->gm[i] = NULL;

	}

	this->rebuildGrid();

}

int GameObjectManager::size() const {

	return this->gm.size();

}