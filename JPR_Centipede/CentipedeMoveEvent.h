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
	Centipede* context;
	CentipedeData* data;
	GameObjectManager* gm;


	void queueLevelChangeCommand();
	void changeLevelAndDirection(CentipedeDirection dir);
	bool nextLevelBlocked();
	void moveLeftRoutine();
	void moveRightRoutine();

public:
	CentipedeMoveEvent(GameObjectManager* gm, Centipede* context);
	CentipedeMoveEvent(const CentipedeMoveEvent& obj);
	~CentipedeMoveEvent();
	CentipedeMoveEvent& operator=(const CentipedeMoveEvent& obj);

	void update(float elapsedTime);

};

#endif
