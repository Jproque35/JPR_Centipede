#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Mushroom.h"


#include "CentipedeMoveEvent.h"
#include "CentipedeHeadState.h"
#include "PlayerInputEvent.h"
#include "BulletFiredEvent.h"
#include "MushroomHitEvent.h"
#include "BulletCollideEvent.h"
#include "CentipedeBodyState.h"
#include "CentipedeMoveEvent.h"
#include "CentipedeHitEvent.h"


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
	queue<GameObject*> misc;

public:
	static GameObjectFactory* getInstance();
	static void resetInstance();
	GameObject* makeObject(ObjectType type, float initX, float initY);
	void storeObject(GameObject* obj);

};

#endif

