#ifndef CENTIPEDEMOVEEVENT_H
#define CENTIPEDEMOVEEVENT_H
#pragma once
#include "GameEvent.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Centipede.h"

class CentipedeMoveEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	Centipede* context;
	CentipedeData* data;

	void queueLevelChangeCommand();
	void changeLevelAndDirection(CentipedeDirection dir);
	bool nextLevelBlocked();
	void moveLeftRoutine();
	void moveRightRoutine();

	bool leftBlocked();
	bool rightBlocked();
	bool upBlocked();
	bool downBlocked();

public:
	CentipedeMoveEvent(Centipede* context);
	CentipedeMoveEvent(const CentipedeMoveEvent& obj);
	~CentipedeMoveEvent();
	CentipedeMoveEvent& operator=(const CentipedeMoveEvent& obj);

	void update(float elapsedTime);

};

#endif
