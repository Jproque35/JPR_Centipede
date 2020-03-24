#ifndef PLAYERINPUTEVENT_H
#define PLAYERINPUTEVENT_H
#pragma once
#include "GameEvent.h"
#include "CommandType.h"

class Player;
class GameObjectManager;
class InputManager;
class CollisionMap;
class GameObject;

class PlayerInputEvent :
	public GameEventListener
{

private:
	Player* context;
	GameObjectManager* gm;
	InputManager* im;
	CollisionMap* cm;
	bool leftBlocked = false, rightBlocked = false, upBlocked = false, downBlocked = false;

	void updateBlockedVars(float xMoveDist, float yMoveDist);
	void processCollision(GameObject* obj, float xMoveDist, float yMoveDist);
	void queueCommand(CommandType type);


public:
	PlayerInputEvent(Player* context);
	PlayerInputEvent(const PlayerInputEvent& obj);
	~PlayerInputEvent();
	PlayerInputEvent& operator=(const PlayerInputEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif

