#ifndef MUSHROOM_H
#define MUSHROOM_H
#pragma once
#include "GameObject.h"

class Mushroom :
	public GameObject
{

private:
	int health = 4;

public:
	Mushroom(float initX, float initY);
	Mushroom(const Mushroom& obj);
	~Mushroom();
	Mushroom& operator=(const Mushroom& obj);

	void init(float xPos, float yPos);

	void decrementHealth();
	void resetHealth();
	int getHealth() const;

};

#endif

