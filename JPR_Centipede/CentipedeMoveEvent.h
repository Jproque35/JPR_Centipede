#ifndef CENTIPEDEMOVEEVENT_H
#define CENTIPEDEMOVEEVENT_H
#pragma once
#include "GameEvent.h"
#include "CentipedeDirection.h"

class GameObjectManager;
class Centipede;
class CollisionMap;

class CentipedeMoveEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm = NULL;
	CollisionMap* cm = NULL;
	Centipede* context = NULL;
	Sound turnSnd;
	bool leftBlocked();
	bool rightBlocked();

	CentipedeMoveEvent(const CentipedeMoveEvent& obj) = delete;
	CentipedeMoveEvent& operator=(const CentipedeMoveEvent& obj) = delete;

	void queueLevelChangeCommand();
	void changeLevelAndDirection(CentipedeDirection dir);
	void moveLeftRoutine();
	void moveRightRoutine();


public:
	CentipedeMoveEvent(Centipede* context);
	~CentipedeMoveEvent();

	void update(float elapsedTime);

};

#endif