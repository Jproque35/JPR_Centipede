#include "Engine.h"

Engine::Engine() {

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	this->cellWidth = resolution.x / 40.0f;
	this->gridHeight = resolution.y / cellWidth;
	this->gridWidth = resolution.x / cellWidth;




	cout << "Grid dimensions are " << this->gridWidth << " by " << this->gridHeight << endl;


	this->window.create(VideoMode(resolution.x, resolution.y), "Simple Game Engine", Style::Default);

}

void Engine::start() {

	Clock clock;

	this->init();

	while (this->window.isOpen()) {

		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();

	}

	delete(this->bullet);
	delete(this->player);
	delete(this->enemies);

}