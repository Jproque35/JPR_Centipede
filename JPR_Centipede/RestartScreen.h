#ifndef RESTARTSCREEN_H
#define RESTARTSCREEN_H
#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class RestartScreen :
	public Screen
{

private:
	float counter = 0.0f;

protected:
	RestartScreen(const RestartScreen& obj) = delete;
	RestartScreen& operator=(const RestartScreen& obj) = delete;
	
	virtual void input(float dtAsSecods);
	virtual void update(float dtAsSeconds);
	virtual void draw();

public:
	RestartScreen();
	virtual ~RestartScreen();

	virtual void init(RenderWindow& w);
	void run();

};

#endif
