#include "Engine.h"

void Engine::draw() {

	window.clear(Color(0, 0, 0, 0));
	
	for (int i = 0; i < this->enemies->size(); i++) {

		if (this->enemies->get(i)->isActive()) {


			RectangleShape enemyDrawable = this->enemies->get(i)->getShape();
			enemyDrawable.scale(cellWidth, cellWidth);
			this->window.draw(enemyDrawable);

		}

	}
	
	for (int i = 0; i < this->obstacles->size(); i++) {

		this->window.draw(this->obstacles->get(i)->getShape());

	}
	RectangleShape drawable = this->player->getShape();
	drawable.scale(cellWidth, cellWidth);

	this->window.draw(drawable);


	if (this->bullet->isActive()) {

		this->window.draw(this->bullet->getShape());


	}
	
	this->window.display();

}