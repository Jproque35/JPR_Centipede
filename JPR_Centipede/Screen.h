#ifndef SCREEN_H
#define SCREEN_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ScreenType.h"

using namespace sf;
using namespace std;

class Screen
{

protected:
	RenderWindow* window;
	ScreenType type;

	virtual void input(float dtAsSecods) = 0;
	virtual void update(float dtAsSeconds) = 0;
	virtual void draw() = 0;

public:
	virtual ~Screen();

	virtual void enterScreen(ScreenType originScreen) = 0;
	virtual void exitScreen(ScreenType destScreen) = 0;

	virtual void init(RenderWindow& w);

	ScreenType getType();
	void run(float dtAsSeconds);

};

#endif
