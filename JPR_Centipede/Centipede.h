#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#pragma once
#include "GameObject.h"
#include "CentipedeData.h"

class Centipede : public GameObject
{

	friend class CentipedeMoveEvent;

private:
	bool head = false;
	CentipedeData* context;
	Centipede* next = NULL;
	bool inReverse = false;

	void updateSub(float elapsedTime);

public:
	Centipede(float initX, float initY);
	Centipede(const Centipede& obj);
	~Centipede();
	Centipede& operator=(const Centipede& obj);

	ObjectData* getData();
	void setNext(Centipede* next);

};

#endif

