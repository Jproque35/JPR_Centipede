#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H
#pragma once
#include <queue>
#include "ObjectType.h"

using namespace std;

class GameObject;

class GameObjectManager {

private:
	static GameObjectManager* instance;
	vector<GameObject*> gm;
	queue<int> freeIds;

	GameObjectManager();
	GameObjectManager(const GameObjectManager& obj) = delete;
	~GameObjectManager();
	GameObjectManager& operator=(const GameObjectManager& obj) = delete;

public:
	static GameObjectManager* getInstance();
	static void resetInstance();

	void init(int x, int y);
	void add(GameObject* obj);
	void update(int i, float elapsedTime);
	void updateAll(float elapsedTime);
	GameObject* get(int i) const;
	void remove(int i);
	int size() const;

};

#endif

