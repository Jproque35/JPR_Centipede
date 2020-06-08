#include "GameScreen.h"
#include "FontManager.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Centipede.h"
#include "EngineConstants.h"

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

	this->reset();

}

void GameScreen::exitScreen(ScreenType destScreen) {




}

void GameScreen::reset() {

	GameObjectManager* gm = GameObjectManager::getInstance();

	for (int i = 0; i < gm->size(); ++i) {

		if (gm->get(i) != NULL) {

			//cout << "Object at " << i << endl;
			this->processObject(gm->get(i));

		}

	}

}

void GameScreen::processObject(GameObject* obj) {

	//if (obj->getType() == ObjectType::Player) {
	if(dynamic_cast<Player*>(obj) != NULL) {
		float initX = floor(EngineConstants::getMapWidth() / 2);
		float initY = floor(EngineConstants::getMapHeight() * 0.8f);

		obj->init(initX, initY);

	}
	/*
	else if (obj->getType() == ObjectType::CentipedeHead
		|| obj->getType() == ObjectType::CentipedeBody) {*/
	else if(dynamic_cast<Centipede*>(obj) != NULL) {

		float initX = round(EngineConstants::getMapWidth() / 2);
		float initY = 0.0f;

		obj->init(initX, initY);

	}

}