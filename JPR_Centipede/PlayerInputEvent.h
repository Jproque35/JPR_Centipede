#ifndef PLAYERINPUTEVENT_H
#define PLAYERINPUTEVENT_H
#pragma once
#include "GameEvent.h"
#include "ObjectController.h"
#include "GameObjectManager.h"
#include "PlayerController.h"

class PlayerInputEvent :
	public GameEventListener
{

private:
	PlayerController* context;
	GameObjectManager* gm;

	void queueCommand(CommandType type);

public:
	PlayerInputEvent(GameObjectManager* gm, int i);
	PlayerInputEvent(const PlayerInputEvent& obj);
	~PlayerInputEvent();
	PlayerInputEvent& operator=(const PlayerInputEvent& obj);

	void update(float elapsedTime);

};

#endif

