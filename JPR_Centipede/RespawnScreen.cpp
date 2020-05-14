#include "RespawnScreen.h"
#include "ScreenManager.h"

RespawnScreen::RespawnScreen()
{



}

RespawnScreen::~RespawnScreen() {



}

void RespawnScreen::init(RenderWindow& w) {


	Screen::init(w);

}

void RespawnScreen::input(float dtAsSeconds) {

	//cout << "Entered RespawnScreen input" << endl;

}

void RespawnScreen::update(float dtAsSeconds) {

	//cout << "Entered RespawnScreen update" << endl;

	this->counter += dtAsSeconds;

	//cout << "Counter is %d" << this->counter << endl;
	if (this->counter >= 3.0f) {

		cout << "Switching screen to restart" << endl;

		ScreenManager* scnm = ScreenManager::getInstance();

		scnm->setCurrentScreen(ScreenType::RestartScreen);

		this->counter = 0.0f;

		//this->window->close();

	}

}

void RespawnScreen::draw() {

	//cout << "Entered RespawnSCreen draw" << endl;

	this->window->clear(Color(0, 255, 0, 0));

	this->window->display();

}