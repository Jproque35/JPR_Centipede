#include "SpriteManager.h"

SpriteManager* SpriteManager::instance = NULL;

SpriteManager::SpriteManager() {};

SpriteManager::~SpriteManager() {};

SpriteManager* SpriteManager::getInstance() {

	if (!instance) {

		instance = new SpriteManager();

	}

	return instance;

}

void SpriteManager::resetInstance() {

	if (instance != NULL) {

		delete(instance);
		instance = NULL;

	}

}