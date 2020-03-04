#ifndef PLAYERBULLETCONTROLLER_H
#define PLAYERBULLETCONTROLLER_H
#pragma once
#include "GameObject.h"
#include "GenericState.h"
#include "PlayerBulletData.h"
#include "PlayerBulletFireCommand.h"

class PlayerBullet :
	public GameObject
{

private:
	PlayerBulletData* context;
	Keyboard::Key key = Keyboard::Unknown;
	float xPos = 0.0f;
	float yPos = 0.0f;

protected:
	void preUpdate(float elapsedTime);
	void postUpdate(float elapsedTime);

public:
	PlayerBullet(float initX, float initY);
	PlayerBullet(const PlayerBullet& obj);
	~PlayerBullet();
	PlayerBullet& operator=(const PlayerBullet& obj);

	ObjectData* getData();
	void setKey(Keyboard::Key key, float x, float y);

};

#endif

