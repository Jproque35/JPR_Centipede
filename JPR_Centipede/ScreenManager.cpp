#include "ScreenManager.h"
#include "Screen.h"
#include "GameScreen.h"
#include "RespawnScreen.h"

ScreenManager* ScreenManager::instance = NULL;

ScreenManager::ScreenManager() {

	this->screens[ScreenType::GameScreen] = new GameScreen();

	cout << "****Created screen " << this->screens[ScreenType::GameScreen] << endl;

	this->screens[ScreenType::RespawnScreen] = new RespawnScreen();
	cout << "****Created screen " << this->screens[ScreenType::RespawnScreen] << endl;
	this->currScreen = this->screens[ScreenType::RespawnScreen];

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

	cout << "CurrScreen is " << currScreen << endl;

	if (this->screens.count(type) > 0) {

		cout << "Setting Screen to " << this->screens[type] << endl;

		this->currScreen = this->screens[type];

		cout << "CurrScreen is now " << currScreen << endl;

	}

}

Screen* ScreenManager::getCurrentScreen() {

	return this->currScreen;

}