#include "RespawnScreen.h"
#include "ScreenManager.h"

RespawnScreen::RespawnScreen() :
	red(0),
	blue(0),
	green(0)
{



}

RespawnScreen::~RespawnScreen() {



}

void RespawnScreen::init(RenderWindow& w) {

	Screen::init(w);

}

void RespawnScreen::input(float dtAsSeconds) {

	cout << "Entered RespawnScreen input" << endl;

}

void RespawnScreen::update(float dtAsSeconds) {

	cout << "Entered RespawnScreen update" << endl;

	this->counter += dtAsSeconds;

	cout << "Counter is %d" << this->counter << endl;
	if (this->counter < 1.0f) {

		this->red = 0;
		this->green = 255;
		this->blue = 0;

	}
	else if (this->counter < 2.0f) {

		this->red = 0;
		this->green = 0;
		this->blue = 255;

	}
	else if (this->counter < 3.0f) {

		this->red = 255;
		this->green = 0;
		this->blue = 0;

	}
	else if (this->counter >= 3.0f) {

		/*
		ScreenManager* const scnm = ScreenManager::getInstance();

		scnm->setCurrentScreen(ScreenType::GameScreen);

		this->counter = 0.0f;*/

		this->window->close();

	}

}

void RespawnScreen::draw() {

	cout << "Entered RespawnSCreen draw" << endl;

	this->window->clear(Color(this->red, this->green, this->blue, 0));

	this->window->display();

}