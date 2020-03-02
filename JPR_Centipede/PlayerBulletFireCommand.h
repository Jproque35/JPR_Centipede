#ifndef PLAYERBULLETFIRECOMMAND_H
#define PLAYERBULLETFIRECOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "PlayerBullet.h"

class PlayerBulletFireCommand :
	public ObjectCommand
{

private:
	PlayerBullet* context;
	float distTravelled = 0.0f;

public:
	PlayerBulletFireCommand(PlayerBullet* context);
	PlayerBulletFireCommand(const PlayerBulletFireCommand& obj);
	~PlayerBulletFireCommand();
	PlayerBulletFireCommand& operator=(const PlayerBulletFireCommand& obj);

	void execute(float elapsedTime);

};

#endif

