#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#pragma once
#include "GameObject.h"
#include "CentipedeDirection.h"

class Centipede : public GameObject
{

private:
	Centipede* next = NULL;
	Centipede* prev = NULL;
	CentipedeDirection dir = CentipedeDirection::Left;
	bool reversed = false;

public:
	Centipede();
	Centipede(const Centipede& obj);
	~Centipede();
	Centipede& operator=(const Centipede& obj);

	void init(float xPos, float yPos);

	void setDirection(CentipedeDirection dir);
	CentipedeDirection getDirection() const;

	void setReversed();
	void unsetReversed();
	bool isReversed() const;

};

#endif

