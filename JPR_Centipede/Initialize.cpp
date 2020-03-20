#include "Engine.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "ScoreObject.h"
#include "InputManager.h"
#include "GameObjectFactory.h"
#include "EventManager.h"
#include "SpriteManager.h"
#include "SoundManager.h"
#include "FontManager.h"
#include "FirePressedEvent.h"
#include "Centipede.h"

EventManager* EventManager::instance = NULL;

inline int Engine::getNumObjects() {

	return 1 + this->numBullets + this->numCentipedes + this->numMushrooms;

}

void Engine::init() {
	int xRes = this->window.getSize().x;
	int yRes = this->window.getSize().y;
	this->gm = GameObjectManager::getInstance();
	this->im = InputManager::getInstance();
	this->scm = ScoreManager::getInstance();
	this->sdm = SoundManager::getInstance();
	this->spm = SpriteManager::getInstance();
	this->em = EventManager::getInstance();
	this->fm = FontManager::getInstance();
	this->objFactory = GameObjectFactory::getInstance();

	this->gm->init(this->gridWidth, this->gridHeight);
	this->sdm->loadFromFile("assets/soundlist.txt");

	this->hudText.setPosition(Vector2f(0.0f, 0.0f));
	this->hudText.setFont(*fm->get(0));
	this->hudText.setCharacterSize(75);
	this->hudText.setFillColor(sf::Color::White);
	this->hudText.setOutlineColor(sf::Color::Black);
	this->hudText.setOutlineThickness(1.0f);

	this->initObjects();
	this->initEvents();

}

void Engine::initObjects() {

	int currPos = 0;

	this->initPlayer(currPos);
	this->initEnemies(currPos);
	this->initMushrooms(currPos);

	cout << "Successfully loaded all objects." << endl;

}

void Engine::initPlayer(int &currPos) {
	
	float initX = floor(this->gridWidth / 2);
	float initY = floor(this->gridHeight / 2);

	GameObject* currObj = this->objFactory->makeObject(ObjectType::Player, initX, initY);
	currObj->init(initX, initY);

	this->gm->add(currObj);

}

void Engine::initEnemies(int &currPos) {

	int initPos = currPos;
	int endPos = currPos + this->numCentipedes;
	cout << "Loading centipede objects..." << endl;

	float initX = round(this->gridWidth / 2);
	float initY = 0.0f;

	vector<Centipede*> centipedes = this->generateCentipede(initX, initY);

	for (int i = 0; i < centipedes.size(); ++i) {

		this->gm->add(centipedes[i]);
		centipedes[i]->init(initX, initY);

	}

}

void Engine::initMushrooms(int &currPos) {

	srand(time(NULL));

	int endPos = currPos + this->numMushrooms;
	cout << "Loading mushroom objects..." << endl;

	while (currPos < endPos) {

		float tempX = rand() % (int)(this->gridWidth);
		float tempY = rand() % (int)(this->gridHeight - 1.0f) + 1;

		GameObject* currObj = 
			this->objFactory->makeObject(ObjectType::Mushroom, tempX, tempY);

		currObj->init(tempX, tempY);

		this->gm->add(currObj);

		//cout << "Loaded mushroom object into slot " << currObj->getId() << " at position " << tempX << ", " << tempY << endl;
		currPos++;

	}

}

void Engine::initEvents() {

	cout << "Loading game events.." << endl;

	this->em->addEvent(new FirePressedEvent());

	cout << "Successfully loaded all game events." << endl;

}

vector<Centipede*> Engine::generateCentipede(float initX, float initY) {

	vector<Centipede*> desire;

	desire.push_back( (Centipede*)objFactory->makeObject(ObjectType::CentipedeHead, initX, initY) );

	for (int i = 0; i < this->numCentipedes - 1; ++i) {

		desire.push_back( (Centipede*)objFactory->makeObject(ObjectType::CentipedeBody, initX, initY) );

	}

	for (int i = 0; i < this->numCentipedes - 1; ++i) {

		desire[i]->setNext(desire[i + 1]);
		cout << "Next for " << desire[i] << " set to " << desire[i + 1] << endl;

	}

	for (int i = this->numCentipedes - 1; i > 0; --i) {

		desire[i]->setPrev(desire[i - 1]);
		cout << "prev for " << desire[i] << " set to " << desire[i - 1] << endl;

	}

	return desire;

}

