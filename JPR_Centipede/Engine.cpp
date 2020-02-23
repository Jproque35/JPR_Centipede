#include "Engine.h"

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

void Engine::start() {

	Clock clock;

	while (this->window.isOpen()) {

		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		input(dtAsSeconds);
		update(dtAsSeconds);
		draw();

	}

	delete(this->objs);

}