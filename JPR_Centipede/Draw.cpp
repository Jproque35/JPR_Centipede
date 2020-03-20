#include "Engine.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "InputManager.h"
#include "ScoreObject.h"

void Engine::draw() {

	window.clear(Color(0, 0, 0, 0));

	for (int i = 0; i < this->gm->size(); i++) {

		if(this->gm->get(i) != NULL) {

			this->drawShape(this->gm->get(i)->getShape());

			if (this->im->isDebugActive()) {

				//this->drawText(this->gm->get(i)->getData()->getPositionText());

			}
			else {

				//this->drawSprite( this->gm->get(i)->getData()->getSprite() );

			}
		}

	}

	stringstream ss;
	ss << "Score: " << this->scm->getScore() << "\n";
	ss << "Lives: " << this->scm->getLives() << "\n";
	this->hudText.setString(ss.str());
	window.draw(this->hudText);

	this->window.display();

}

void Engine::drawShape(CircleShape shape) {

	shape.scale(cellWidth, cellWidth);
	Vector2f drawablePosition = shape.getPosition();

	drawablePosition.x *= this->cellWidth;
	drawablePosition.y *= this->cellWidth;
	shape.setPosition(drawablePosition);

	this->window.draw(shape);

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


