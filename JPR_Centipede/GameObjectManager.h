#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H
#pragma once
#include "GameObject.h"
#include "GridManager.h"
#include <SFML/Graphics.hpp>

class GameObjectManager {

private:
	std::vector<GameObject*> objs;

public:
	GameObjectManager(int size);
	~GameObjectManager();
	void add(int i, GameObject* obj);
	GameObject* get(int i);
	int size();

};

#endif

