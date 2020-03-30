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
	GameObjectManager* gm;
	CollisionMap* cm;
	Centipede* context;
	Sound turnSnd;

	void queueLevelChangeCommand();
	void changeLevelAndDirection(CentipedeDirection dir);
	void moveLeftRoutine();
	void moveRightRoutine();

	bool leftBlocked();
	bool rightBlocked();

public:
	CentipedeMoveEvent(Centipede* context);
	CentipedeMoveEvent(const CentipedeMoveEvent& obj);
	~CentipedeMoveEvent();
	CentipedeMoveEvent& operator=(const CentipedeMoveEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif