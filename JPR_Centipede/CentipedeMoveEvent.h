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


	CentipedeMoveEvent(const CentipedeMoveEvent& obj) = delete;
	CentipedeMoveEvent& operator=(const CentipedeMoveEvent& obj) = delete;

	void queueLevelChangeCommand();
	void changeLevelAndDirection(CentipedeDirection dir);
	void moveLeftRoutine();
	void moveRightRoutine();

	bool leftBlocked();
	bool rightBlocked();

public:
	CentipedeMoveEvent(Centipede* context);
	~CentipedeMoveEvent();

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif