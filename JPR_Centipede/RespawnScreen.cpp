#include "RespawnScreen.h"
#include "ScreenManager.h"

RespawnScreen::RespawnScreen() {



}

RespawnScreen::~RespawnScreen() {



}

void RespawnScreen::init(RenderWindow& w) {

	Screen::init(w);

}

void RespawnScreen::input(float dtAsSeconds) {



}

void RespawnScreen::update(float dtAsSeconds) {

	this->counter += dtAsSeconds;

	cout << "Counter is %d" << this->counter << endl;

	if (this->counter >= 3.0f) {

		ScreenManager* const scnm = ScreenManager::getInstance();

		scnm->setCurrentScreen(ScreenType::GameScreen);

		this->counter = 0.0f;

	}

}

void RespawnScreen::draw() {

	this->window->clear(Color(0, 0, 255, 0));

	this->window->display();

}