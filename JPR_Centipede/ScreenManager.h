#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#pragma once
#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ScreenType.h"

using namespace sf;
using namespace std;

class Screen;

class ScreenManager {

private:
	static ScreenManager* instance;
	Screen* currScreen;
	unordered_map<ScreenType, Screen*> screens;

	ScreenManager();
	ScreenManager(const ScreenManager& obj) = delete;
	~ScreenManager();
	ScreenManager& operator=(const ScreenManager& obj) = delete;

public:
	static ScreenManager* getInstance();
	static void resetInstance();

	void init(RenderWindow& w);
	void setCurrentScreen(ScreenType newType);
	Screen* getCurrentScreen() const;


};

#endif