#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H
#pragma once
#include <queue>
#include "ObjectType.h"

using namespace std;

class Player;
class GameObject;

class GameObjectManager {

private:
	static GameObjectManager* instance;
	vector<GameObject*> gm;
	int pid = -1;
	queue<int> freeIds;

	GameObjectManager();
	GameObjectManager(const GameObjectManager& obj) = delete;
	~GameObjectManager();
	GameObjectManager& operator=(const GameObjectManager& obj) = delete;

public:
	static GameObjectManager* getInstance();
	static void resetInstance();

	void init(int x, int y);
	void setPlayerObject(int id);
	Player* getPlayerObject();
	void add(GameObject* obj);
	void update(int i, float elapsedTime);
	void updateAll(float elapsedTime);
	GameObject* get(int i) const;
	GameObject* removeAndGet(int i);
	void remove(int i);
	int size() const;

};

#endif

