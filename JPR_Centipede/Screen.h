#ifndef SCREEN_H
#define SCREEN_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Screen
{

protected:
	virtual void input(float dtAsSecods) = 0;
	virtual void update(float dtAsSeconds) = 0;
	virtual void draw(RenderWindow& window) = 0;

public:
	virtual ~Screen();
	virtual void init(RenderWindow& w) = 0;
	void run(RenderWindow& w);

};

#endif
