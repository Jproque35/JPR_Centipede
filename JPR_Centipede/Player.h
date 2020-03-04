#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#pragma once
#include "GameObject.h"
#include "GenericState.h"
#include "PlayerData.h"

class Player :
	public GameObject
{

private:
	Keyboard::Key key = Keyboard::Unknown;
	PlayerData* context;
	void preUpdate(float elapsedTime);
	void postUpdate(float elapsedTime);

public:
	Player(float initX, float initY);
	Player(const Player& obj);
	~Player();
	Player& operator=(const Player& obj);

	ObjectData* getData();
	void setKey(Keyboard::Key key);

};

#endif

