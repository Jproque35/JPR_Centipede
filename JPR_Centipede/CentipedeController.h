#ifndef CENTIPEDECONTROLLER_H
#define CENTIPEDECONTROLLER_H
#pragma once
#include "ObjectController.h"
#include "Centipede.h"

enum class CentipedeDirection {Left, Right, Up, Down};

class CentipedeController : public ObjectController
{

	friend class CentipedeMoveEvent;

private:
	bool head = false;
	Centipede* context;
	CentipedeDirection dir = CentipedeDirection::Left;
	CentipedeController* next = NULL;
	bool inReverse = false;
	void updateSub(float elapsedTime);
	void collisionSub(float elapsedTime);


public:
	CentipedeController(Centipede* context);
	GameObject* getData();
	void setNext(CentipedeController* next);

};

#endif

