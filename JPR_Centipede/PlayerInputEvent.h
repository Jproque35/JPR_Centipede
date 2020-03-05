#ifndef PLAYERINPUTEVENT_H
#define PLAYERINPUTEVENT_H
#pragma once
#include "GameEvent.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Player.h"

class PlayerInputEvent :
	public GameEventListener
{

private:
	Player* context;
	GameObjectManager* gm;

	void queueCommand(CommandType type);

public:
	PlayerInputEvent(GameObjectManager* gm, Player* context);
	PlayerInputEvent(const PlayerInputEvent& obj);
	~PlayerInputEvent();
	PlayerInputEvent& operator=(const PlayerInputEvent& obj);

	void update(float elapsedTime);

};

#endif

