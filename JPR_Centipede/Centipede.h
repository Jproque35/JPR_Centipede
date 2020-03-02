#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#pragma once
#include "GameObject.h"
#include "PlayerBullet.h"
#include <iostream>

enum class CentipedeDirection { Left, Right };

class Centipede: public GameObject {

	friend class CentipedeController;
	friend class CentipedeMoveEvent;

private:
	CentipedeDirection dir = CentipedeDirection::Left;

public:
	Centipede(float initX, float initY);
	Centipede(const Centipede& obj);
	~Centipede();
	Centipede& operator=(const Centipede& obj);

};

#endif

