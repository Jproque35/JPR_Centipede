#include "GameScreen.h"
#include "FontManager.h"

GameScreen::GameScreen()
{
	FontManager* fm = FontManager::getInstance();

	this->hudText.setPosition(Vector2f(0.0f, 0.0f));
	this->hudText.setFont(*fm->get(0));
	this->hudText.setCharacterSize(75);
	this->hudText.setFillColor(sf::Color::White);
	this->hudText.setOutlineColor(sf::Color::Black);
	this->hudText.setOutlineThickness(1.0f);

	this->type = ScreenType::GameScreen;

}

GameScreen::~GameScreen() {



}

void GameScreen::enterScreen(ScreenType originScreen) {



}

void GameScreen::exitScreen(ScreenType destScreen) {




}