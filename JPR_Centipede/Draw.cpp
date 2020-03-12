#include "Engine.h"

void Engine::draw() {

	window.clear(Color(0, 0, 0, 0));
	
	for (int i = 0; i < this->gm->size(); i++) {

		if(this->gm->get(i) != NULL) {

			if(this->gm->get(i)->getData()->isActive()) {

				this->drawShape( this->gm->get(i)->getData() );

				if (this->im->isDebugActive()) {

					this->drawText(this->gm->get(i)->getData()->getPositionText());

				}

			}
		}

	}
	
	Text hudText = this->sm->getScoreText();

	window.draw(hudText);

	Text testHud;

	this->window.display();

}

void Engine::drawShape(ObjectData* obj) {

	CircleShape drawable = obj->getShape();
	Vector2f drawablePosition = obj->getPosition();
	drawable.scale(cellWidth, cellWidth);
	drawablePosition.x *= this->cellWidth;
	drawablePosition.y *= this->cellWidth;
	drawable.setPosition(drawablePosition);
	this->window.draw(drawable);

}

void Engine::drawText(const Text& drawable) {

	Text currText = drawable;
	float xPos = currText.getPosition().x * this->cellWidth;
	float yPos = currText.getPosition().y * this->cellWidth;

	currText.setPosition(Vector2f(xPos, yPos));

	this->window.draw(currText);
}