#include "GameObjectManager.h"

GameObjectManager::GameObjectManager(int size) {

	this->objs.resize(size);

	for (int i = 0; i < this->objs.size(); i++) {

		this->objs[i] = NULL;

	}

}

GameObjectManager::~GameObjectManager() {

	for (int i = 0; i < this->objs.size(); i++) {

		delete(this->objs[i]);

	}

}

void GameObjectManager::add(int i, GameObject* obj) {

	if (i < this->objs.size() && i >= 0) {

		this->objs[i] = obj;

	}

}

GameObject* GameObjectManager::get(int i) {

	return this->objs[i];

}

int GameObjectManager::size() {

	return this->objs.size();

}