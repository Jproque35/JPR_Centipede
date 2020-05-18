#ifndef ENGINECONSTANTS_H
#define ENGINECONSTANTS_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

struct EngineConstants {

private:
	static const int gridHeight = 40;
	static const int gridWidth = 30;
	static const int numCentipedes = 10;
	static const int numMushrooms = 50;

public:
	static int getMapHeight();
	static int getMapWidth();
	static int getNumCentipedes();
	static int getNumMushrooms();
	static float getCellSize(const RenderWindow& w);

};

#endif
