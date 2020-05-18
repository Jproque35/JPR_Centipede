#include "EngineConstants.h"

int EngineConstants::getMapHeight() {

	return gridHeight;

}

int EngineConstants::getMapWidth() {

	return gridWidth;

}

int EngineConstants::getNumCentipedes() {

	return numCentipedes;

}

int EngineConstants::getNumMushrooms() {

	return numMushrooms;

}

float EngineConstants::getCellSize(const RenderWindow& w) {

	return w.getSize().y / gridHeight;

}