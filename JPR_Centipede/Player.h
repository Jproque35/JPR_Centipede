#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#pragma once
#include "GameObject.h"

class Player :
	public GameObject
{

public:
	Player();
	Player(const Player& obj);
	~Player();
	Player& operator=(const Player& obj);

	void init(float xPos, float yPos);

};

#endif

