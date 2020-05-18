#include "GameScreen.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "ScoreObject.h"
#include "InputManager.h"
#include "GameObjectFactory.h"
#include "EventManager.h"
#include "SpriteManager.h"
#include "SoundManager.h"
#include "FontManager.h"
#include "CollisionMap.h"
#include "FirePressedEvent.h"
#include "Centipede.h"
#include "CentipedeManager.h"
#include "EngineConstants.h"

void GameScreen::init(RenderWindow& w) {

	Screen::init(w);

	int xRes = this->window->getSize().x;
	int yRes = this->window->getSize().y;

	//this->cellWidth = this->window->getSize().y / this->gridHeight;

	this->gm = GameObjectManager::getInstance();
	this->im = InputManager::getInstance();
	this->scm = ScoreManager::getInstance();

	this->sdm = SoundManager::getInstance();
	this->sdm->loadFromFile("assets/soundlist.txt");

	this->spm = SpriteManager::getInstance();
	this->em = EventManager::getInstance();
	this->fm = FontManager::getInstance();
	this->cm = CollisionMap::getInstance();
	this->objFactory = GameObjectFactory::getInstance();

	this->gm->init(EngineConstants::getMapWidth(), EngineConstants::getMapHeight());
	this->cm->init(EngineConstants::getMapWidth(), EngineConstants::getMapHeight());

	this->hudText.setPosition(Vector2f(0.0f, 0.0f));
	this->hudText.setFont(*fm->get(0));
	this->hudText.setCharacterSize(75);
	this->hudText.setFillColor(sf::Color::White);
	this->hudText.setOutlineColor(sf::Color::Black);
	this->hudText.setOutlineThickness(1.0f);

	this->centiMngr = CentipedeManager::getInstance();

	this->initObjects();
	this->initEvents();

	this->cm->clear();
	this->cm->buildMap();

}

void GameScreen::initObjects() {

	this->initPlayer();
	this->initEnemies();
	this->initMushrooms();

	cout << "Successfully loaded all objects." << endl;

}

void GameScreen::initPlayer() {

	float initX = floor(EngineConstants::getMapWidth() / 2);
	float initY = floor(EngineConstants::getMapHeight() / 2);

	GameObject* currObj = this->objFactory->makeObject(ObjectType::Player, initX, initY);
	currObj->init(initX, initY);

	this->gm->add(currObj);
	this->gm->setPlayerObject(currObj->getId());

}

void GameScreen::initEnemies() {

	cout << "Loading centipede objects..." << endl;

	float initX = round(EngineConstants::getMapWidth() / 2);
	float initY = 0.0f;

	vector<Centipede*> centipedes = this->centiMngr->generateCentipede(10);

	for (int i = 0; i < centipedes.size(); ++i) {

		this->gm->add(centipedes[i]);
		centipedes[i]->init(initX, initY);

	}

}

void GameScreen::initMushrooms() {

	srand(time(NULL));

	cout << "Loading mushroom objects..." << endl;

	float tempX = -1.0f, tempY = -1.0f;

	for (int i = 0; i < EngineConstants::getNumMushrooms(); ++i) {

		tempX = rand() % (int)(EngineConstants::getMapWidth());
		tempY = rand() % (int)(EngineConstants::getMapHeight() - 1.0f) + 1;

		GameObject* currObj =
			this->objFactory->makeObject(ObjectType::Mushroom, tempX, tempY);

		currObj->init(tempX, tempY);

		this->gm->add(currObj);

	}

}

void GameScreen::initEvents() {

	cout << "Loading game events.." << endl;

	this->em->addEvent(new FirePressedEvent());

	cout << "Successfully loaded all game events." << endl;

}