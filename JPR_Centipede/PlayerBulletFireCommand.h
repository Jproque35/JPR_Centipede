#ifndef PLAYERBULLETFIRECOMMAND_H
#define PLAYERBULLETFIRECOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "PlayerBulletData.h"

class PlayerBulletFireCommand :
	public ObjectCommand
{

private:
	PlayerBulletData* context;
	float distTravelled = 0.0f;

public:
	PlayerBulletFireCommand(PlayerBulletData* context);
	PlayerBulletFireCommand(const PlayerBulletFireCommand& obj);
	~PlayerBulletFireCommand();
	PlayerBulletFireCommand& operator=(const PlayerBulletFireCommand& obj);

	void execute(float elapsedTime);

};

#endif

