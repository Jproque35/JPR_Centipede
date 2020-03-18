#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#pragma once
#include "GameObject.h"
#include "GenericState.h"
#include "PlayerData.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "CollisionManager.h"
#include "CommandFactory.h"

class Player :
	public GameObject
{

private:
	PlayerData* context;
	bool upBlocked = false;
	bool downBlocked = false;
	bool rightBlocked = false;
	bool leftBlocked = false;
	void updateCollisions();
	void queueStateCommand(CommandType type);

public:
	Player(float initX, float initY);
	Player(const Player& obj);
	~Player();
	Player& operator=(const Player& obj);

	void init(float xPos, float yPos);
	ObjectData* getData() const;
	void update(float elapsedTime);

};

#endif

