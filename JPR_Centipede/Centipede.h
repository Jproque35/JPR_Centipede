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
	Centipede(const Centipede& obj) = delete;
	Centipede& operator=(const Centipede& obj) = delete;

public:
	Centipede();
	~Centipede();

	void init(float xPos, float yPos);

	void setNext(Centipede* next);
	Centipede* getNext() const;

	void setPrev(Centipede* prev);
	Centipede* getPrev() const;

	void setDirection(CentipedeDirection dir);
	CentipedeDirection getDirection() const;

	void setReversed();
	void unsetReversed();
	bool isReversed() const;

};

#endif

