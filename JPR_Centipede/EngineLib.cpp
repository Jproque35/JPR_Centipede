#include "EngineLib.h"
#include "CollisionMap.h"
#include "GameObject.h"
#include <unordered_map>

inline void EngineLib::addIntersectsObj(const vector<GameObject*>& currList, vector<GameObject*>& desire, 
	unordered_map<GameObject*, int>& freqs, const FloatRect& colBox) {

	for (int k = 0; k < currList.size(); ++k) {

		if (currList[k]->getCollisionBox().intersects(colBox)
			&& freqs.count(currList[k]) == 0) {

			freqs[currList[k]] = freqs.count(currList[k]);
			desire.push_back(currList[k]);

		}

	}

}

vector<GameObject*> EngineLib::getIntersectsObj(GameObject* obj) {

	CollisionMap* cm = CollisionMap::getInstance();
	FloatRect colBox = obj->getCollisionBox();

	int xStart = floor(colBox.left);
	int yStart = floor(colBox.top);
	int xEnd = floor(colBox.left + colBox.width);
	int yEnd = floor(colBox.top + colBox.height);

	vector<GameObject*> desire;
	vector<GameObject*> currList;

	unordered_map<GameObject*, int> freqs;

	for (int i = xStart; i <= xEnd; ++i) {

		for (int j = yStart; j <= yEnd; ++j) {

			currList = cm->get(i, j);

			addIntersectsObj(currList, desire, freqs, colBox);

		}

	}

	return desire;

}

vector<GameObject*> EngineLib::getIntersectsPt(float xPos, float yPos) {

	CollisionMap* cm = CollisionMap::getInstance();

	vector<GameObject*> desire;
	vector<GameObject*> currList = cm->get(xPos, yPos);

	for (int i = 0; i < currList.size(); ++i) {

		if (currList[i]->getCollisionBox().contains(xPos, yPos)) {

			desire.push_back(currList[i]);

		}

	}

	return desire;

}