#include "Screen.h"

Screen::~Screen() {}

void Screen::init(RenderWindow& w) {

	this->window = &w;

}

void Screen::run() {

	Clock clock;

	while (this->window->isOpen()) {

		Event event;
		while (this->window->pollEvent(event)) {

			if (event.type == Event::Closed) {

				this->window->close();

			}

		}

		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		this->input(dtAsSeconds);
		this->update(dtAsSeconds);
		this->draw();

	}

}