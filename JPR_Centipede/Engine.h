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

	Engine();
	Engine(const Engine& obj) = delete;
	~Engine();
	Engine& operator=(const Engine& obj) = delete;

	void init();

public:
	static Engine* getInstance();
	static void resetInstance();
	void start();

};

#endif