#include "RestartScreen.h"
#include "ScreenManager.h"

RestartScreen::RestartScreen()
{



}

RestartScreen::~RestartScreen() {



}

void RestartScreen::init(RenderWindow& w) {

	Screen::init(w);

}

void RestartScreen::input(float dtAsSeconds) {

	//cout << "Entered RestartScreen input" << endl;

}

void RestartScreen::update(float dtAsSeconds) {

	//cout << "Entered RRestartScreen update" << endl;

	this->counter += dtAsSeconds;

	//cout << "Counter is %d" << this->counter << endl;

	if (this->counter >= 3.0f) {

		cout << "Switching screen to respawn" << endl;

		ScreenManager* scnm = ScreenManager::getInstance();

		scnm->setCurrentScreen(ScreenType::RespawnScreen);

		this->counter = 0.0f;

		//this->window->close();

	}

}

void RestartScreen::draw() {

	//cout << "Entered RestartScreen draw" << endl;

	this->window->clear(Color(255, 0, 0, 0));

	this->window->display();

}