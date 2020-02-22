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

void GridManager::add(GameObject* obj, int x, int y) {

	if (this->inBounds(x, y)) {

		this->objs[this->getKey(x, y)].push_back(obj);

	}

}

vector<GameObject*> GridManager::get(int x, int y) {

	//cout << "Retrieving objects at location " << x << ", " << y << endl;

	if (this->inBounds(x, y)) {

		return this->objs[this->getKey(x, y)];

	}

	return {};

}