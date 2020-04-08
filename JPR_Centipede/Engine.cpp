#include "Engine.h"
#include "GameObjectManager.h"
#include "ScoreObject.h"
#include "InputManager.h"
#include "GameObjectFactory.h"
#include "EventManager.h"
#include "SpriteManager.h"
#include "SoundManager.h"
#include "FontManager.h"
#include "CentipedeManager.h"

Engine* Engine::instance = NULL;

Engine::Engine() {

	Vector2f resolution;
	//resolution.x = VideoMode::getDesktopMode().width;
	//resolution.y = VideoMode::getDesktopMode().height;
	resolution.x = 1600;
	resolution.y = 900;

	this->cellWidth = resolution.y / this->gridHeight;

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
	CentipedeManager::resetInstance();

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

		this->input(dtAsSeconds);
		this->update(dtAsSeconds);
		this->draw();

	}

}