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
	vector<GameObject*> gm;
	InputManager* im;
	GridManager* grid;
	ScoreObject* hud;

	void rebuildGrid();

public:
	GameObjectManager(int size, int x, int y);
	GameObjectManager(const GameObjectManager& obj);
	~GameObjectManager();
	GameObjectManager& operator=(const GameObjectManager& obj);

	InputManager* getInputManager();
	ScoreObject* getHudObject();
	int getGridWidth();
	int getGridHeight();
	void add(int i, GameObject* obj);
	void update(int i, float elapsedTime);
	void updateAll(float elapsedTime);
	vector<GameObject*> get(int x, int y);
	GameObject* get(int i);
	bool hasType(ObjectType type, int x, int y);
	void erase(int i);
	int size();

};

#endif

