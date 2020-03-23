#ifndef ENGINELIB_H
#define ENGINELIB_H
#pragma once
#include <vector>

using namespace std;

class GameObject;

class EngineLib {

public:
	static vector<GameObject*> getIntersectsObj(GameObject* obj);
	static vector<GameObject*> getIntersectsPt(float xPos, float yPos);

};

#endif