#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H
#pragma once
#include <vector>
#include <iostream>
#include "ObjectType.h"

using namespace std;

class GameObject;

class CollisionMap
{

private:
	static CollisionMap* instance;
	int width = 0;
	int height = 0;
	vector<vector<GameObject*>> map;

	CollisionMap();
	CollisionMap(const CollisionMap& obj) = delete;
	~CollisionMap();
	CollisionMap& operator=(const CollisionMap& obj) = delete;

	bool inBounds(float x, float y);
	int getKey(float x,float y);

public:

	static CollisionMap* getInstance();
	static void resetInstance();

	void init(int width, int height);
	int getWidth();
	int getHeight();
	void buildMap();
	void clear();
	void add(GameObject* obj);
	vector<GameObject*> get(int x, int y);
	bool containsType(ObjectType type, float xPos, float yPos);


};

#endif

