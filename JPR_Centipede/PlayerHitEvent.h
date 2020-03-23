#ifndef PLAYERHITEVENT_H
#define PLAYERHITEVENT_H
#pragma once
#include "GameEvent.h"

class Player;

class PlayerHitEvent :
	public GameEventListener
{

private:
	Player* context;
	bool isCentipede(GameObject* obj);
	bool intersectsCentipede();


public:
	PlayerHitEvent(Player* context);
	PlayerHitEvent(const PlayerHitEvent& obj);
	~PlayerHitEvent();
	PlayerHitEvent& operator=(const PlayerHitEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif

