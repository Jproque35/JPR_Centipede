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
#include "CentipedeMoveLeftCommand.h"
#include "CentipedeController.h"

using namespace sf;
using namespace std;

class Engine {

private: 
	RenderWindow window;
	GameObjectManager* enemies;
	GameObjectManager* obstacles;
	Player* player;
	PlayerBullet* bullet;
	float cellWidth = 0.0f;
	float gridHeight = 0.0f;
	float gridWidth = 0.0f;
	CentipedeController* testController;


	void input();
	void init();
	void update(float dtAsSeconds);
	void draw();
	void drawShape(GameObject* obj);

public:
	Engine();
	void start();

};

#endif