#include "ScreenManager.h"
#include "Screen.h"
#include "GameScreen.h"

ScreenManager* ScreenManager::instance = NULL;

ScreenManager::ScreenManager() {

	this->screens[ScreenType::GameScreen] = new GameScreen();
	this->currScreen = this->screens[ScreenType::GameScreen];

}

ScreenManager::~ScreenManager() {

	for (auto it = this->screens.begin(); it != this->screens.end(); ++it) {

		delete(it->second);

	}

}

ScreenManager* ScreenManager::getInstance() {

	if (!instance) {

		instance = new ScreenManager();

	}

	return instance;

}

void ScreenManager::resetInstance() {

	if (instance) {

		delete(instance);
		instance = NULL;

	}

}

void ScreenManager::init(RenderWindow& w) {

	for (auto it = this->screens.begin(); it != this->screens.end(); ++it) {

		it->second->init(w);

	}

}

void ScreenManager::setCurrentScreen(ScreenType type) {

	if (this->screens.count(type) > 0) {

		this->currScreen = this->screens[type];

	}

}

Screen* ScreenManager::getCurrentScreen() const {

	return this->currScreen;

}