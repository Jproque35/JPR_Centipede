#ifndef PLAYERINPUTEVENT_H
#define PLAYERINPUTEVENT_H
#pragma once
#include "GameEvent.h"
#include "CommandType.h"

class Player;
class GameObjectManager;
class InputManager;

class PlayerInputEvent :
	public GameEventListener
{

private:
	Player* context;
	GameObjectManager* gm;
	InputManager* im;

	void queueCommand(CommandType type);

public:
	PlayerInputEvent(Player* context);
	PlayerInputEvent(const PlayerInputEvent& obj);
	~PlayerInputEvent();
	PlayerInputEvent& operator=(const PlayerInputEvent& obj);

	void update(float elapsedTime);

};

#endif

