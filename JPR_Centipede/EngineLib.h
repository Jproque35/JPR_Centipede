#ifndef ENGINELIB_H
#define ENGINELIB_H
#pragma once
#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class GameObject;

class EngineLib {

private:
	static void addIntersectsObj(const vector<GameObject*>& currList, vector<GameObject*>& desire,
		unordered_map<GameObject*, int>& freqs, const FloatRect& colBox);

public:
	static vector<GameObject*> getIntersectsObj(GameObject* obj);
	static vector<GameObject*> getIntersectsPt(float xPos, float yPos);

};

#endif