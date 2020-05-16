#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#pragma once
#include "Screen.h"

class GameObjectManager;
class InputManager;
class ScoreManager;
class EventManager;
class FontManager;
class SpriteManager;
class SoundManager;
class GameObjectFactory;
class CollisionMap;
class Centipede;
class CentipedeManager;

class GameScreen :
	public Screen
{

private:
	GameObjectManager* gm = NULL;
	InputManager* im = NULL;
	ScoreManager* scm = NULL;
	EventManager* em = NULL;
	FontManager* fm = NULL;
	SpriteManager* spm = NULL;
	SoundManager* sdm = NULL;
	GameObjectFactory* objFactory = NULL;
	CollisionMap* cm = NULL;
	CentipedeManager* centiMngr = NULL;

	Text hudText;

	int cellWidth = 0.0f;
	int gridHeight = 40.0f;
	int gridWidth = 30.0f;
	int bulletsStart = -1;
	int numBullets = 1;
	int numCentipedes = 10;
	int numMushrooms = 50;

	void initObjects();
	void initPlayer();
	void initEnemies();
	void initMushrooms();
	void initEvents();
	void executeObjectEventListeners(float elapsedTime);
	void drawShape(RenderWindow& window, CircleShape shape);
	void drawSprite(RenderWindow& window, Sprite spr);
	void drawBackgroundTile(RenderWindow& window, Sprite img);
	void drawText(RenderWindow& window, const Text& drawable);

protected:
	void input(float dtAsSecods);
	void update(float dtAsSeconds);
	void draw();

public:
	GameScreen();
	~GameScreen();

	virtual void enterScreen(ScreenType originScreen) override;
	virtual void exitScreen(ScreenType destScreen) override;

	GameScreen& operator=(const GameScreen& obj);
	virtual void init(RenderWindow& w) override;

};

#endif