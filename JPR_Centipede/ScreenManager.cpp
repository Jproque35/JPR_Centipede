#include "ScreenManager.h"
#include "Screen.h"
#include "GameScreen.h"
#include "RespawnScreen.h"
#include "RestartScreen.h"

ScreenManager* ScreenManager::instance = NULL;

ScreenManager::ScreenManager() {

	this->screens[ScreenType::RespawnScreen] = new RespawnScreen();

	this->screens[ScreenType::RestartScreen] = new RestartScreen();

	this->screens[ScreenType::GameScreen] = new GameScreen();

	this->currScreen = this->screens[ScreenType::RestartScreen];

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

void ScreenManager::setCurrentScreen(ScreenType newType) {

	//cout << "CurrScreen is " << currScreen << endl;

	if (this->screens.count(newType) > 0) {

		//cout << "Setting Screen to " << this->screens[type] << endl;

		ScreenType prevType = this->currScreen->getType();

		this->currScreen->exitScreen(newType);

		this->currScreen = this->screens[newType];

		this->currScreen->enterScreen(prevType);

		//cout << "CurrScreen is now " << currScreen << endl;

	}
	else {

		//cout << "Could not set screen" << endl;

	}

}

Screen* ScreenManager::getCurrentScreen() const {

	return this->currScreen;

}