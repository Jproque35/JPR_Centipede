#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "GameObject.h"

class Player :
	public GameObject
{

public:
	Player(int id, float initX, float initY);

};

#endif

