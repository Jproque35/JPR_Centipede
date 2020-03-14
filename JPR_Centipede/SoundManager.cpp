#include "SoundManager.h"

SoundManager* SoundManager::instance = NULL;

SoundManager::SoundManager() {};

SoundManager::~SoundManager() {};

SoundManager* SoundManager::getInstance() {

	if (!instance) {

		instance = new SoundManager();

	}

	return instance;

}

void SoundManager::resetInstance() {

	if (instance != NULL) {

		delete(instance);
		instance = NULL;

	}

}