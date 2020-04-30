#ifndef MUSHROOM_H
#define MUSHROOM_H
#pragma once
#include "GameObject.h"

class Mushroom :
	public GameObject
{

private:
	int health = 4;
	Mushroom(const Mushroom& obj) = delete;
	Mushroom& operator=(const Mushroom& obj) = delete;

public:
	Mushroom(float initX, float initY);
	~Mushroom();

	void init(float xPos, float yPos);

	void decrementHealth();
	void resetHealth();
	int getHealth() const;

};

#endif

