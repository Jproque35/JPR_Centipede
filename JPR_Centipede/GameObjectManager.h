#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H
#pragma once
#include "GameObject.h"
#include "GridManager.h"
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "ScoreObject.h"

using namespace std;

class GameObjectManager {

private:
	static GameObjectManager* instance;
	vector<GameObject*> gm;
	GridManager* grid;

	GameObjectManager() {};
	GameObjectManager(const GameObjectManager& obj);
	~GameObjectManager();
	GameObjectManager& operator=(const GameObjectManager& obj);

	void rebuildGrid();

public:
	static GameObjectManager* getInstance();
	static void resetInstance();
	void init(int size, int x, int y);
	int getGridWidth() const;
	int getGridHeight() const;
	void add(int i, GameObject* obj);
	void update(int i, float elapsedTime);
	void updateAll(float elapsedTime);
	vector<GameObject*> get(int x, int y) const ;
	GameObject* get(int i) const;
	bool hasType(ObjectType type, int x, int y) const;
	void erase(int i);
	int size() const;

};

#endif

