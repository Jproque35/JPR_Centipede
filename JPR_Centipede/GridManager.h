#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H
#pragma once
#include <unordered_map>
#include <vector>
#include "ObjectController.h"
#include <iostream>

using namespace std;

class GridManager
{

private:
	int width = 0;
	int height = 0;
	vector<vector<ObjectController*>> objs;
	bool inBounds(int x, int y);
	int getKey(int x, int y);

public:
	GridManager(int width, int height);
	~GridManager();
	int getWidth();
	int getHeight();
	void clear();
	bool hasType(ObjectType type, int x, int y);
	void add(ObjectController* obj);
	vector<ObjectController*> get(int x, int y);


};

#endif

