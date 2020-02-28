#ifndef CENTIPEDECONTROLLER_H
#define CENTIPEDECONTROLLER_H
#pragma once
#include "ObjectController.h"
#include "Centipede.h"

class CentipedeController : public ObjectController
{

	friend class CentipedeMoveEvent;

private:
	bool head = false;
	Centipede* context;
	CentipedeController* next = NULL;
	bool inReverse = false;
	void updateSub(float elapsedTime);


public:
	CentipedeController(Centipede* context);
	GameObject* getData();
	void setNext(CentipedeController* next);

};

#endif

