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
#include "GridManager.h"
#include "MushroomController.h"

using namespace sf;
using namespace std;

class Engine {

private: 
	RenderWindow window;
	GameObjectManager* objs;
	GridManager* grid;
	float cellWidth = 0.0f;
	float gridHeight = 0.0f;
	float gridWidth = 0.0f;
	int bulletsStart = -1;
	int numBullets = 1;
	int numCentipedes = 10;
	int numMushrooms = 20;
	vector<ObjectController*> objectControllers;
	vector<vector<GameObject*>> getCollisionObjects(GameObject* obj);
	queue<PlayerBulletController*> loadedBullets;
	int getNumObjects();
	float lastFiredTime = 0.0f;


	void input(float dtAsSeconds);
	void init();
	void buildGridState();
	void update(float dtAsSeconds);
	void draw();
	void drawShape(GameObject* obj);

public:
	Engine();
	void start();

};

#endif