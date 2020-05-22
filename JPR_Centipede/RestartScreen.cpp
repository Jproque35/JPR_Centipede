#include "RestartScreen.h"
#include "ScreenManager.h"
#include "InputManager.h"
#include "TextManager.h"

RestartScreen::RestartScreen()
{

	this->type = ScreenType::RestartScreen;

}

RestartScreen::~RestartScreen() {



}

void RestartScreen::init(RenderWindow& w) {

	Screen::init(w);

}

void RestartScreen::enterScreen(ScreenType originScreen) {



}

void RestartScreen::exitScreen(ScreenType destScreen) {




}

void RestartScreen::input(float dtAsSeconds) {

	//cout << "Entered RestartScreen input" << endl;

	InputManager* im = InputManager::getInstance();

	im->update();

}

void RestartScreen::update(float dtAsSeconds) {

	//cout << "Entered RRestartScreen update" << endl;

	this->counter += dtAsSeconds;

	//cout << "Counter is %d" << this->counter << endl;

	/*
	if (this->counter >= 3.0f) {

		cout << "Switching screen to respawn" << endl;

		ScreenManager* scnm = ScreenManager::getInstance();

		scnm->setCurrentScreen(ScreenType::GameScreen);

		this->counter = 0.0f;

		//this->window->close();

	}*/



	InputManager* im = InputManager::getInstance();

	if ( im->isFirePressed() ) {

		cout << "Switching screens" << endl;

		ScreenManager* scnm = ScreenManager::getInstance();

		scnm->setCurrentScreen(ScreenType::GameScreen);

	}

}

void RestartScreen::draw() {

	//cout << "Entered RestartScreen draw" << endl;

	TextManager* tm = TextManager::getInstance();

	this->window->clear(Color(0, 0, 0, 0));

	Text* startText = tm->get(TextType::StartText);

	float textHeight = startText->getLocalBounds().height;
	float textWidth = startText->getLocalBounds().width;

	startText->setPosition(Vector2f(this->window->getSize().x / 2 - textWidth / 2, 
							this->window->getSize().y / 2 - textHeight / 2));

	this->window->draw( *tm->get(TextType::StartText) );

	this->window->display();

}