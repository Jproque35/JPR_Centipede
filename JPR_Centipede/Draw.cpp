#include "Engine.h"

void Engine::draw() {

	window.clear(Color(0, 0, 0, 0));
	
	for (int i = 0; i < this->enemies->size(); i++) {

		if (this->enemies->get(i)->isActive()) {

			this->window.draw(this->enemies->get(i)->getShape());

		}

	}
	
	for (int i = 0; i < this->obstacles->size(); i++) {

		this->window.draw(this->obstacles->get(i)->getShape());

	}

	this->window.draw(this->player->getShape());
	if (this->bullet->isActive()) {

		this->window.draw(this->bullet->getShape());

	}
	
	this->window.display();

}