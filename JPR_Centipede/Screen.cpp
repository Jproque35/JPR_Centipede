#include "Screen.h"

Screen::~Screen() {}

void Screen::run(Window& w) {

	Clock clock;

	while (w.isOpen()) {

		Event event;
		while (w.pollEvent(event)) {

			if (event.type == Event::Closed) {

				w.close();

			}

		}

		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		this->input(dtAsSeconds);
		this->update(dtAsSeconds);
		this->draw();

	}

}