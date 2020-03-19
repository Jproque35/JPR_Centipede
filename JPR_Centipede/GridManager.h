#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H
#pragma once
#include <vector>
#include <iostream>
#include "ObjectType.h"

using namespace std;

class GameObject;

class GridManager
{

private:
	int width = 0;
	int height = 0;
	vector<vector<GameObject*>> gm;

	bool inBounds(int x, int y);
	int getKey(float x,float y);

public:
	GridManager(int width, int height);
	GridManager(const GridManager& obj);
	~GridManager();
	GridManager& operator=(const GridManager& obj);

	int getWidth();
	int getHeight();
	void clear();
	bool hasType(ObjectType type, int x, int y);
	void add(GameObject* obj);
	vector<GameObject*> get(int x, int y);


};

#endif

