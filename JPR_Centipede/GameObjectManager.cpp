#include "GameObjectManager.h"
#include "GameObjectFactory.h"
#include "GameObject.h"

GameObjectManager* GameObjectManager::instance = 0;

GameObjectManager::GameObjectManager() {

}

GameObjectManager::~GameObjectManager() {

	for (int i = 0; i < this->gm.size(); i++) {

		if (this->gm[i] != NULL) {

			delete(this->gm[i]);
			this->gm[i] = NULL;

		}

	}

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

}

void GameObjectManager::setPlayerObject(int id) {

	this->pid = id;

}

Player* GameObjectManager::getPlayerObject() {

	return (Player*)this->gm[pid];

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

	}

}

void GameObjectManager::updateAll(float elapsedTime) {

	for (int i = 0; i < gm.size(); i++) {

		if (this->gm[i] != NULL) {
			this->gm[i]->update(elapsedTime);
		}

	}

}

GameObject* GameObjectManager::get(int i) const {

	return this->gm[i];

}

GameObject* GameObjectManager::removeAndGet(int i) {

	if (this->gm[i] != NULL) {

		GameObject* desire = this->gm[i];
		this->gm[i]->setId(-1);
		this->gm[i] = NULL;
		return desire;

	}

}

void GameObjectManager::remove(int i) {

	if (this->gm[i] != NULL) {

		GameObjectFactory* objFactory = GameObjectFactory::getInstance();
		this->gm[i]->setId(-1);
		objFactory->storeObject(this->gm[i]);
		this->freeIds.push(i);
		this->gm[i] = NULL;

	}

}

int GameObjectManager::size() const {

	return this->gm.size();

}