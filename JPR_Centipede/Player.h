#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#pragma once
#include "GameObject.h"

class Player :
	public GameObject
{

private:
	Player(const Player& obj) = delete;
	Player& operator=(const Player& obj) = delete;

public:
	Player();
	~Player();

	virtual void init(float xPos, float yPos) override;

};

#endif

