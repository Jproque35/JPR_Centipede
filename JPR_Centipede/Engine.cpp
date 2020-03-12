#include "Engine.h"

Engine* Engine::instance = NULL;

Engine::Engine() {

	Vector2f resolution;
	//resolution.x = VideoMode::getDesktopMode().width;
	//resolution.y = VideoMode::getDesktopMode().height;
	resolution.x = 1600;
	resolution.y = 900;

	this->cellWidth = resolution.y / 40.0f;
	this->gridHeight = 40.0f;
	this->gridWidth = 20.0f;

	this->window.create(VideoMode(this->gridWidth * cellWidth, this->gridHeight * cellWidth), "Simple Game Engine", Style::Default);

	this->init();

}

Engine::Engine(const Engine& obj) {}

Engine::~Engine() {

	GameObjectManager::resetInstance();
	InputManager::resetInstance();
	ScoreManager::resetInstance();
	delete(this->em);

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