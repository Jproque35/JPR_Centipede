#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H
#pragma once
#include "ObjectController.h"
#include "GridManager.h"
#include <SFML/Graphics.hpp>

using namespace std;

class GameObjectManager {

private:
	vector<ObjectController*> gm;
	GridManager* grid = NULL;

	void rebuildGrid();

public:
	GameObjectManager(int size, int x, int y);
	GameObjectManager(const GameObjectManager& obj);
	~GameObjectManager();
	GameObjectManager& operator=(const GameObjectManager& obj);

	int getGridWidth();
	int getGridHeight();
	void add(int i, ObjectController* obj);
	void update(int i, float elapsedTime);
	void updateAll(float elapsedTime);
	vector<ObjectController*> get(int x, int y);
	ObjectController* get(int i);
	bool hasType(ObjectType type, int x, int y);
	void erase(int i);
	int size();

};

#endif

