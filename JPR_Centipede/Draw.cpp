#include "Engine.h"

void Engine::draw() {

	window.clear(Color(0, 0, 0, 0));
	
	for (int i = 0; i < this->objs->size(); i++) {

		if(this->objs->get(i)->isActive()) {

			this->drawShape( this->objs->get(i) );

		}

	}
	
	this->window.display();

}

void Engine::drawShape(GameObject* obj) {

	CircleShape drawable = obj->getShape();
	Vector2f drawablePosition = obj->getPosition();
	drawable.scale(cellWidth, cellWidth);
	drawablePosition.x *= this->cellWidth;
	drawablePosition.y *= this->cellWidth;
	drawable.setPosition(drawablePosition);
	this->window.draw(drawable);

}