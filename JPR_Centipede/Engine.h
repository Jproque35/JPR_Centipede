#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>;
#include <vector>
#include <queue>
#include <sstream>

using namespace sf;
using namespace std;

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

class Engine {

private:
	static Engine* instance;
	RenderWindow window;
	GameObjectManager* gm;
	InputManager* im;
	ScoreManager* scm;
	EventManager* em;
	FontManager* fm;
	SpriteManager* spm;
	SoundManager* sdm;
	GameObjectFactory* objFactory;
	CollisionMap* cm;
	CentipedeManager* centiMngr;

	Texture bgImg;
	Sprite background;
	vector<Sprite> backgroundTiles;

	Text hudText;

	int cellWidth = 0.0f;
	int gridHeight = 40.0f;
	int gridWidth = 30.0f;
	int bulletsStart = -1;
	int numBullets = 1;
	int numCentipedes = 10;
	int numMushrooms = 50;
	int getNumObjects();

	Engine();
	Engine(const Engine& obj);
	~Engine();
	Engine& operator=(const Engine& obj);

	void input(float dtAsSeconds);
	void init();
	void initObjects();
	void initPlayer();
	void initEnemies();
	void initMushrooms();
	void initEvents();
	void executeObjectEventListeners(float elapsedTime);
	void update(float dtAsSeconds);
	void draw();
	void drawShape(CircleShape shape);
	void drawSprite(Sprite spr);
	void drawBackgroundTile(Sprite img);
	void drawText(const Text& drawable);

public:
	static Engine* getInstance();
	static void resetInstance();
	void start();

};

#endif