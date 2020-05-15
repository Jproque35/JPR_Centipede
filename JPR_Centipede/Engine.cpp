#include "Engine.h"
#include "GameScreen.h"
#include "ScreenManager.h"

Engine* Engine::instance = NULL;

Engine::Engine() {

	Vector2f resolution;
	//resolution.x = VideoMode::getDesktopMode().width;
	//resolution.y = VideoMode::getDesktopMode().height;
	resolution.x = 1600;
	resolution.y = 900;

	this->cellWidth = resolution.y / this->gridHeight;

	this->window.create(VideoMode(this->gridWidth * cellWidth, this->gridHeight * cellWidth), "Simple Game Engine", Style::Default);

	this->screenManager = ScreenManager::getInstance();
	this->screenManager->init(this->window);

}

Engine::~Engine() {

	ScreenManager::resetInstance();

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

		//cout << screenManager->getCurrentScreen() << endl;

		this->screenManager->getCurrentScreen()->run(dtAsSeconds);

	}

}