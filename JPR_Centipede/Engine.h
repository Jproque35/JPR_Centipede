#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>;
#include <vector>
#include <queue>
#include "GameObjectManager.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Centipede.h"
#include "Mushroom.h"
#include "ObjectCommand.h"
#include "CentipedeController.h"
#include "PlayerController.h"
#include "PlayerBulletController.h"
#include "MushroomController.h"
#include "CollisionManager.h"
#include "EventManager.h"

using namespace sf;
using namespace std;

class Engine {

	friend class EventManager;

private: 
	RenderWindow window;
	GameObjectManager* objs;
	EventManager* em;
	queue<PlayerBulletController*> loadedBullets;


	float cellWidth = 0.0f;
	float gridHeight = 0.0f;
	float gridWidth = 0.0f;
	int bulletsStart = -1;
	int numBullets = 1;
	int numCentipedes = 1;
	int numMushrooms = 20;
	int getNumObjects();
	float lastFiredTime = 0.0f;


	void input(float dtAsSeconds);
	void init();
	void initObjects();
	void initEvents();
	void update(float dtAsSeconds);
	void draw();
	void drawShape(GameObject* obj);

public:
	Engine();
	void start();

};

#endif