#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>;
#include <vector>
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
	CentipedeController* testController;
	PlayerController* playerController;
	PlayerBulletController* bulletController;
	vector<vector<GameObject*>> getCollisionObjects(GameObject* obj);


	void input();
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