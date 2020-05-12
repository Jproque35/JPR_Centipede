#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>;
#include <vector>
#include <queue>
#include <sstream>

using namespace sf;
using namespace std;


class ScreenManager;
class Screen;

class Engine {

private:
	static Engine* instance;

	ScreenManager* screenManager;
	Screen* currScreen;

	RenderWindow window;

	Text hudText;

	int cellWidth = 0.0f;
	int gridHeight = 40.0f;
	int gridWidth = 30.0f;
	int bulletsStart = -1;
	int numBullets = 1;
	int numCentipedes = 10;
	int numMushrooms = 50;

	Engine();
	Engine(const Engine& obj) = delete;
	~Engine();
	Engine& operator=(const Engine& obj) = delete;

public:
	static Engine* getInstance();
	static void resetInstance();
	void start();

};

#endif