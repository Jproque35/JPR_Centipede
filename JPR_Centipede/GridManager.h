#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H
#pragma once
#include <unordered_map>
#include <vector>
#include "GameObject.h"
#include <iostream>

using namespace std;

class GridManager
{

private:
	int width = 0;
	int height = 0;
	vector<vector<GameObject*>> objs;
	bool inBounds(int x, int y);
	int getKey(int x, int y);

public:
	GridManager(int width, int height);
	~GridManager();
	int getWidth();
	int getHeight();
	void clear();
	void add(GameObject* obj, int x, int y);
	vector<GameObject*> get(int x, int y);


};

#endif

