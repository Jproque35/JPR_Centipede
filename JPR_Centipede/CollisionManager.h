#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#pragma once
#include "ObjectController.h"
#include "GameObjectManager.h"
#include "GridManager.h"

class CollisionManager
{

public:
	CollisionManager() = delete;
	~CollisionManager() = delete;
	static bool intersects(ObjectController* obj1, ObjectController* obj2);
	static vector<vector<ObjectController*>> getGridObjects( ObjectController* obj, GameObjectManager* gm);

};

#endif

