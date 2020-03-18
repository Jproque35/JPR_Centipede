#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#pragma once
#include "GameObject.h"
#include "GameObjectManager.h"

class CollisionManager
{

public:
	CollisionManager() = delete;
	~CollisionManager() = delete;
	static bool intersects(GameObject* obj1, GameObject* obj2);
	static vector<GameObject*> getGridObjects( GameObject* obj );

};

#endif

