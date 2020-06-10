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

	PlayerHitEvent(const PlayerHitEvent& obj) = delete;
	PlayerHitEvent& operator=(const PlayerHitEvent& obj) = delete;

public:
	PlayerHitEvent(Player* context);
	~PlayerHitEvent();

	void update(float elapsedTime);

};

#endif

