#include "Engine.h"
#include "GameScreen.h"

Engine* Engine::instance = NULL;

Engine::Engine() {

	Vector2f resolution;
	//resolution.x = VideoMode::getDesktopMode().width;
	//resolution.y = VideoMode::getDesktopMode().height;
	resolution.x = 1600;
	resolution.y = 900;

	this->cellWidth = resolution.y / this->gridHeight;

	this->window.create(VideoMode(this->gridWidth * cellWidth, this->gridHeight * cellWidth), "Simple Game Engine", Style::Default);

	this->screen = new GameScreen();
	this->screen->init(this->window);

}

Engine::~Engine() {

	delete(screen);

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

		this->screen->run(this->window);

	}

}