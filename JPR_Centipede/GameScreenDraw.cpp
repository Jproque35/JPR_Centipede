#include "GameScreen.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "InputManager.h"
#include "ScoreObject.h"
#include "EngineConstants.h"

void GameScreen::draw() {

	GameObjectManager* gm = GameObjectManager::getInstance();
	InputManager* im = InputManager::getInstance();
	ScoreManager* scm = ScoreManager::getInstance();

	this->window->clear(Color(0, 0, 0, 0));


	for (int i = 0; i < gm->size(); i++) {

		if (gm->get(i) != NULL) {

			this->drawShape(*this->window, gm->get(i)->getShape());

			if (im->isDebugActive()) {

				//this->drawText(this->gm->get(i)->getData()->getPositionText());

			}
			else {

				//this->drawSprite( this->gm->get(i)->getData()->getSprite() );

			}
		}

	}

	stringstream ss;
	ss << "Score: " << scm->getScore() << "\n";
	ss << "Lives: " << scm->getLives() << "\n";
	this->hudText.setString(ss.str());
	this->window->draw(this->hudText);

	this->window->display();

}

void GameScreen::drawShape(RenderWindow& window, CircleShape shape) {

	float cellSize = EngineConstants::getCellSize(*this->window);

	shape.scale(cellSize, cellSize);
	Vector2f drawablePosition = shape.getPosition();

	drawablePosition.x *= cellSize;
	drawablePosition.y *= cellSize;
	shape.setPosition(drawablePosition);

	window.draw(shape);

}

void GameScreen::drawSprite(RenderWindow& window, Sprite spr) {

	float cellSize = EngineConstants::getCellSize(*this->window);
	Vector2u size = spr.getTexture()->getSize();

	//cout << this->cellWidth << endl;
	//cout << size.x << ", " << size.y << endl;

	float newXSize = cellSize / (float)size.x;
	float newYSize = cellSize / (float)size.y;

	//cout << "New scale is " << newXSize << ", " << newYSize << endl;

	spr.scale(newXSize, newYSize);
	float scaleX = spr.getPosition().x * cellSize;
	float scaleY = spr.getPosition().y * cellSize;
	spr.setPosition(Vector2f(scaleX, scaleY));
	window.draw(spr);

}

void GameScreen::drawText(RenderWindow& window, const Text& drawable) {

	float cellSize = EngineConstants::getCellSize(*this->window);
	Text currText = drawable;
	float xPos = currText.getPosition().x * cellSize;
	float yPos = currText.getPosition().y * cellSize;

	currText.setPosition(Vector2f(xPos, yPos));

	window.draw(currText);
}

void GameScreen::drawBackgroundTile(RenderWindow& window, Sprite img) {}