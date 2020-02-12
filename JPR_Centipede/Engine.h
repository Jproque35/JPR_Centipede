#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObjectManager.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "MovingObject.h"
#include "DestroyableObject.h"

using namespace sf;

class Engine {

private: 
	RenderWindow window;
	GameObjectManager* enemies;
	GameObjectManager* obstacles;
	Player* player;
	PlayerBullet* bullet;

	void input();
	void init();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();
	void start();

};