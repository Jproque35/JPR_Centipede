#include "Engine.h"

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

	GameObject* currObj = this->objFactory->makeObject(ObjectType::PlayerData, initX, initY);

	this->gm->add(currObj);
	currObj->getData()->activate();
	bulletsStart = ++currPos;

	int endPos = currPos + this->numBullets;
	cout << "Loading bullet objects..." << endl;

	while (currPos < endPos) {

		currObj = this->objFactory->makeObject(ObjectType::PlayerProjectile, initX, initY);

		this->gm->add(currObj);
		cout << "Loaded bullet object into slot " << currObj->getData()->getId() << endl;
		++currPos;

	}
}

void Engine::initEnemies(int &currPos) {

	int initPos = currPos;
	int endPos = currPos + this->numCentipedes;
	cout << "Loading centipede objects..." << endl;

	float initX = floor(this->gridWidth / 2);
	float initY = 0.0f;

	GameObject* currObj = this->objFactory->makeObject(ObjectType::CentipedeData, initX, initY);

	this->gm->add( currObj );
	currObj->getData()->activate();

	cout << "Loaded centipede object into slot " << currObj->getData()->getId() << endl;
	++currPos;

	while (currPos < endPos) {

		if (currPos > initPos) {



		}

		currObj = this->objFactory->makeObject(ObjectType::CentipedeBody, initX, initY);

		this->gm->add(currObj);
		cout << "Loaded centipede object into slot " << currObj->getData()->getId() << endl;
		++currPos;

	}

	
	int currPos2 = initPos;

	while (currPos2 < endPos) {

		CentipedeData* currData = (CentipedeData*)(this->gm->get(currPos2)->getData());

		if (currPos2 < endPos - 1) {

			currData->setNextId(currPos2 + 1);
			cout << "Next for " << currPos2 << " set to " << currPos2 + 1 << endl;

		}

		currPos2++;

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
			this->objFactory->makeObject(ObjectType::MushroomData, tempX, tempY);

		this->gm->add(currObj);
		currObj->getData()->activate();
		cout << "Loaded mushroom object into slot " << currObj->getData()->getId() << " at position " << tempX << ", " << tempY << endl;
		currPos++;

	}

}

void Engine::initEvents() {

	cout << "Loading game events.." << endl;

	cout << "Successfully loaded all game events." << endl;

}