#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "GameObject.h"

class Player :
	public GameObject
{

public:
	Player(float initX, float initY);
	Player(const Player& obj);
	~Player();
	Player& operator=(const Player& obj);
};

#endif

