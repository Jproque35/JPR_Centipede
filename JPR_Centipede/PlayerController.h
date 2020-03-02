#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#pragma once
#include "ObjectController.h"
#include "Player.h"

class PlayerController :
	public ObjectController
{

private:
	Keyboard::Key key = Keyboard::Unknown;
	Player* context;
	void updateSub(float elapsedTime);
	void collisionSub(GameObject* obj);

public:
	PlayerController(Player* context);
	PlayerController(const PlayerController& obj);
	~PlayerController();
	PlayerController& operator=(const PlayerController& obj);

	GameObject* getData();
	void setKey(Keyboard::Key key);

};

#endif

