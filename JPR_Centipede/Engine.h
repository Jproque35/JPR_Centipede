#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>;
#include <vector>
#include <queue>
#include "GameObjectManager.h"
#include "ObjectCommand.h"
#include "Centipede.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Mushroom.h"
#include "CollisionManager.h"
#include "EventManager.h"
#include "GameObjectFactory.h"

using namespace sf;
using namespace std;

class Engine {

private:
	static Engine* instance;
	RenderWindow window;
	GameObjectManager* gm;
	InputManager* im;
	ScoreManager* scm;
	EventManager* em;
	SpriteManager* spm;
	SoundManager* sdm;

	Texture bgImg;
	Sprite background;
	vector<Sprite> backgroundTiles;

	int cellWidth = 0.0f;
	int gridHeight = 0.0f;
	int gridWidth = 0.0f;
	int bulletsStart = -1;
	int numBullets = 1;
	int numCentipedes = 11;
	int numMushrooms = 50;
	int getNumObjects();

	Engine();
	Engine(const Engine& obj);
	~Engine();
	Engine& operator=(const Engine& obj);

	void input(float dtAsSeconds);
	void init();
	void initObjects();
	void initPlayer(int &currPos);
	void initEnemies(int &currPos);
	void initMushrooms(int &currPos);
	void initEvents();
	void executeObjectEventListeners(float elapsedTime);
	void update(float dtAsSeconds);
	void draw();
	void drawShape(ObjectData* obj);
	void drawSprite(Sprite spr);
	void drawBackgroundTile(Sprite img);
	void drawText(const Text& drawable);

public:
	static Engine* getInstance();
	static void resetInstance();
	void start();

};

#endif