#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#pragma once
#include "GameObject.h"
#include "PlayerBullet.h"
#include <iostream>

class Centipede: public GameObject {

	friend class CentipedeController;
	friend class CentipedeMoveRightCommand;
	friend class CentipedeMoveLeftCommand;
	friend class CentipedeMoveDownCommand;
	friend class CentipedeMoveUpCommand;

public:

	Centipede(int id, float initX, float initY);

};

#endif

