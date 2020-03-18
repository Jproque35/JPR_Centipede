#ifndef PLAYERHITEVENT_H
#define PLAYERHITEVENT_H
#pragma once
#include "GameEvent.h"
#include "GameObjectFactory.h"
#include "ScoreObject.h"

class PlayerHitEvent :
	public GameEventListener
{

private:
	Player* context;
	bool hasCentipede(float xPos, float yPos);

public:
	PlayerHitEvent(Player* context);
	PlayerHitEvent(const PlayerHitEvent& obj);
	~PlayerHitEvent();
	PlayerHitEvent& operator=(const PlayerHitEvent& obj);

	void update(float elapsedTime);

};

#endif

