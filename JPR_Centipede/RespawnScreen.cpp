#include "RespawnScreen.h"
#include "ScreenManager.h"
#include "TextManager.h"

RespawnScreen::RespawnScreen()
{

	this->type = ScreenType::RespawnScreen;

}

RespawnScreen::~RespawnScreen() {



}

void RespawnScreen::init(RenderWindow& w) {


	Screen::init(w);

}

void RespawnScreen::enterScreen(ScreenType originScreen) {



}

void RespawnScreen::exitScreen(ScreenType destScreen) {




}

void RespawnScreen::input(float dtAsSeconds) {

	//cout << "Entered RespawnScreen input" << endl;

}

void RespawnScreen::update(float dtAsSeconds) {

	//cout << "Entered RespawnScreen update" << endl;

	this->counter += dtAsSeconds;

	//cout << "Counter is %d" << this->counter << endl;
	if (this->counter >= 3.0f) {

		cout << "Switching screen to game" << endl;

		ScreenManager* scnm = ScreenManager::getInstance();

		scnm->setCurrentScreen(ScreenType::GameScreen);

		this->counter = 0.0f;

		//this->window->close();

	}

}

void RespawnScreen::draw() {

	//cout << "Entered RespawnSCreen draw" << endl;

	TextManager* tm = TextManager::getInstance();

	this->window->clear(Color(0, 0, 0, 0));

	Text* respawnText = tm->get(TextType::RespawnText);

	float textHeight = respawnText->getLocalBounds().height;
	float textWidth = respawnText->getLocalBounds().width;

	respawnText->setPosition(Vector2f((this->window->getSize().x - textWidth) / 2,
		(this->window->getSize().y - textHeight) / 2));

	this->window->draw(*respawnText);

	this->window->display();

}