#include "SoundManager.h"

SoundManager* SoundManager::instance = NULL;

SoundManager::SoundManager() {

	this->bufs = new SoundBuffer[128];
	this->bufs[0].loadFromFile("assets/sounds/mmzx_vent_mx_shoot.wav");

};

SoundManager::~SoundManager() {

	delete[] this->bufs;

};

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

SoundBuffer SoundManager::get(int i) const {

	return this->bufs[i];

}