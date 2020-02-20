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

public:
	PlayerController(Player* context);
	void setKey(Keyboard::Key key);

};

