#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#pragma once
#include <vector>
#include <queue>
#include "ObjectType.h"

using namespace std;

class Mushroom;
class PlayerBullet;
class Player;
class Centipede;
class GameObject;

class GameObjectFactory
{

private:
	static GameObjectFactory* instance;

	GameObjectFactory();
	GameObjectFactory(const GameObjectFactory& obj) = delete;
	~GameObjectFactory();
	GameObjectFactory& operator=(const GameObjectFactory& obj) = delete;

	queue<Mushroom*> mushrooms;
	queue<PlayerBullet*> bullets;
	queue<Player*> player;
	queue<Centipede*> centipedes;
	queue<GameObject*> misc;

public:
	static GameObjectFactory* getInstance();
	static void resetInstance();
	GameObject* makeObject(ObjectType type, float initX, float initY);
	void storeObject(GameObject* obj);

};

#endif

