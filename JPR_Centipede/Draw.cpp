#include "Engine.h"

void Engine::draw() {

	window.clear(Color(0, 0, 0, 0));
	
	for (int i = 0; i < this->enemies->size(); i++) {

		if (this->enemies->get(i)->isActive()) {

			this->drawShape(this->enemies->get(i));

		}

	}
	
	for (int i = 0; i < this->obstacles->size(); i++) {

		this->drawShape(this->obstacles->get(i));

	}

	this->drawShape(this->player);

	if (this->bullet->isActive()) {

		this->drawShape(this->bullet);


	}
	
	this->window.display();

}

void Engine::drawShape(GameObject* obj) {

	RectangleShape drawable = obj->getShape();
	Vector2f drawablePosition = obj->getPosition();
	drawable.scale(cellWidth, cellWidth);
	drawablePosition.x *= this->cellWidth;
	drawablePosition.y *= this->cellWidth;
	drawable.setPosition(drawablePosition);
	this->window.draw(drawable);

}