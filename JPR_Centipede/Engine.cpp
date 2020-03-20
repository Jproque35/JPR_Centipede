#include "Engine.h"
#include "GameObjectManager.h"
#include "ScoreObject.h"
#include "InputManager.h"
#include "GameObjectFactory.h"
#include "EventManager.h"
#include "SpriteManager.h"
#include "SoundManager.h"
#include "FontManager.h"

Engine* Engine::instance = NULL;

Engine::Engine() {

	Vector2f resolution;
	//resolution.x = VideoMode::getDesktopMode().width;
	//resolution.y = VideoMode::getDesktopMode().height;
	resolution.x = 1600;
	resolution.y = 900;

	this->cellWidth = resolution.y / 40.0f;
	this->gridHeight = 40;
	this->gridWidth = 40;

	this->bgImg.loadFromFile("assets/sprites/bg.png");
	this->background.setTexture(this->bgImg);
	this->background.setPosition(Vector2f(0.0f, 0.0f));

	Vector2u bgSize = this->background.getTexture()->getSize();
	float bgX = (float)(this->cellWidth * this->gridWidth) / (float)bgSize.x;
	float bgY = (float)(this->cellWidth * this->gridHeight) / (float)bgSize.y;
	this->background.setScale(bgX, bgY);

	//this->backgroundTiles = new Sprite[this->gridHeight * this->gridWidth];
	
	this->backgroundTiles.resize(this->gridHeight * this->gridWidth);

	for (int i = 0; i < this->gridHeight * this->gridWidth; i++) {

		(this->backgroundTiles[i]).setTexture(this->bgImg);
		int tempX = (i % this->gridWidth) * this->cellWidth;
		int tempY = (i * this->gridWidth) * this->cellWidth;
		this->backgroundTiles[i].setPosition(Vector2f( tempX, tempY ));

	}

	this->window.create(VideoMode(this->gridWidth * cellWidth, this->gridHeight * cellWidth), "Simple Game Engine", Style::Default);

	this->init();

}

Engine::Engine(const Engine& obj) {}

Engine::~Engine() {

	GameObjectManager::resetInstance();
	InputManager::resetInstance();
	ScoreManager::resetInstance();
	SoundManager::resetInstance();
	SpriteManager::resetInstance();
	GameObjectFactory::resetInstance();
	EventManager::resetInstance();

}

Engine& Engine::operator=(const Engine& obj) {

	return *this;

}

Engine* Engine::getInstance() {

	if (!instance) {

		instance = new Engine();

	}

	return instance;

}

void Engine::resetInstance() {

	delete(instance);
	instance = NULL;

}

void Engine::start() {

	Clock clock;

	while (this->window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {

				window.close();

			}

		}

		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		input(dtAsSeconds);
		update(dtAsSeconds);
		draw();

	}

}