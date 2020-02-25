#include "GridManager.h"

GridManager::GridManager(int width, int height) {

	this->width = width;
	this->height = height;
	this->objs.resize(this->width * this->height);

}

GridManager::~GridManager() {

}

inline bool GridManager::inBounds(int x, int y) {

	if (0 <= x && x < this->width) {

		return 0 <= y && y < this->height;
		
	}

	return false;

}

inline int GridManager::getKey(int x, int y) {

	return y * this->width + x;

}

int GridManager::getWidth() {

	return this->width;

}

int GridManager::getHeight() {

	return this->height;

}

void GridManager::clear() {

	this->objs.clear();
	this->objs.resize(this->width * this->height);

}

bool GridManager::hasType(ObjectType type, int x, int y) {

	if (!this->inBounds(x, y)) {

		return false;

	}

	vector<ObjectController*> currList = this->objs[this->getKey(x, y)];

	for (int i = 0; i < currList.size(); i++) {

		if (currList[i]->getData()->getType() == type) {

			return true;

		}

	}

	return false;

}

void GridManager::add(ObjectController* obj) {

	int x = obj->getData()->getPosition().x;
	int y = obj->getData()->getPosition().y;

	if (this->inBounds(x, y)) {

		this->objs[this->getKey(x, y)].push_back(obj);

	}

}

vector<ObjectController*> GridManager::get(int x, int y) {

	//cout << "Retrieving objects at location " << x << ", " << y << endl;

	if (this->inBounds(x, y)) {

		return this->objs[this->getKey(x, y)];

	}

	return {};

}