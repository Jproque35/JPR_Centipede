#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H
#pragma once
#include <queue>
#include "ObjectType.h"

using namespace std;

class GameObject;
class GridManager;

class GameObjectManager {

private:
	static GameObjectManager* instance;
	vector<GameObject*> gm;
	//GameObjectFactory* objFactory;
	GridManager* grid;
	queue<int> freeIds;
	int largestFreeId = -1;

	GameObjectManager();
	GameObjectManager(const GameObjectManager& obj) = delete;
	~GameObjectManager();
	GameObjectManager& operator=(const GameObjectManager& obj) = delete;

	void rebuildGrid();

public:
	static GameObjectManager* getInstance();
	static void resetInstance();

	void init(int x, int y);
	int getGridWidth() const;
	int getGridHeight() const;
	void add(GameObject* obj);
	void update(int i, float elapsedTime);
	void updateAll(float elapsedTime);
	vector<GameObject*> get(int x, int y) const;
	GameObject* get(int i) const;
	bool hasType(ObjectType type, int x, int y) const;
	void erase(int i);
	int size() const;

};

#endif

