#include "Engine.h"

void Engine::draw() {

	window.clear(Color(0, 0, 0, 0));
	
	//this->window.draw(this->background);

	//this->window.draw(this->backgroundTiles[2]);

	/*
	for (int i = 0; i < this->gridWidth * this->gridHeight; i++) {

		this->window.draw(this->backgroundTiles[i]);
	}*/

	for (int i = 0; i < this->gm->size(); i++) {

		if(this->gm->get(i) != NULL) {

			if(this->gm->get(i)->getData()->isActive()) {

				this->drawShape(this->gm->get(i)->getData());

				if (this->im->isDebugActive()) {


					this->drawText(this->gm->get(i)->getData()->getPositionText());

				}
				else {

					//this->drawSprite( this->gm->get(i)->getData()->getSprite() );

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

void Engine::drawSprite(Sprite spr) {

	Vector2u size = spr.getTexture()->getSize();

	//cout << this->cellWidth << endl;
	//cout << size.x << ", " << size.y << endl;

	float newXSize = (float)this->cellWidth / (float)size.x;
	float newYSize = (float)this->cellWidth / (float)size.y;

	//cout << "New scale is " << newXSize << ", " << newYSize << endl;

	spr.scale(newXSize, newYSize);
	float scaleX = spr.getPosition().x * this->cellWidth;
	float scaleY = spr.getPosition().y * this->cellWidth;
	spr.setPosition(Vector2f(scaleX, scaleY));
	this->window.draw(spr);

}

void Engine::drawText(const Text& drawable) {

	Text currText = drawable;
	float xPos = currText.getPosition().x * this->cellWidth;
	float yPos = currText.getPosition().y * this->cellWidth;

	currText.setPosition(Vector2f(xPos, yPos));

	this->window.draw(currText);
}

void Engine::drawBackgroundTile(Sprite img) {}


