#ifndef PLAYERBULLETCONTROLLER_H
#define PLAYERBULLETCONTROLLER_H
#pragma once
#include "ObjectController.h"
#include "PlayerBullet.h"
#include "PlayerBulletFireCommand.h"

class PlayerBulletController :
	public ObjectController
{

private:
	PlayerBullet* context;
	Keyboard::Key key = Keyboard::Unknown;
	float xPos = 0.0f;
	float yPos = 0.0f;

protected:
	void updateSub(float elapsedTime);

public:
	PlayerBulletController(PlayerBullet* context);
	void setKey(Keyboard::Key key, float x, float y);

};

#endif

