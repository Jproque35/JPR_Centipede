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
	GameObject* getData();
	void setKey(Keyboard::Key key);

};

