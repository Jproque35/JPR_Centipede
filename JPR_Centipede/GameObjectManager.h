#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H
#pragma once
#include "ObjectData.h"
#include <SFML/Graphics.hpp>

class GameObjectManager {

private:
	std::vector<ObjectData*> objs;

public:
	GameObjectManager(int size);
	~GameObjectManager();
	void add(int i, ObjectData* obj);
	ObjectData* get(int i);
	int size();

};

#endif

