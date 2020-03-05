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
	RenderWindow window;
	GameObjectManager* gm;
	EventManager* em;
	queue<PlayerBullet*> loadedBullets;

	float cellWidth = 0.0f;
	float gridHeight = 0.0f;
	float gridWidth = 0.0f;
	int bulletsStart = -1;
	int numBullets = 1;
	int numCentipedes = 20;
	int numMushrooms = 50;
	int getNumObjects();

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

public:	
	Engine();
	Engine(const Engine& obj);
	~Engine();
	Engine& operator=(const Engine& obj);
	void start();

};

#endif