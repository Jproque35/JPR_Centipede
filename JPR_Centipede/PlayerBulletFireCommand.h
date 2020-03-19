#ifndef PLAYERBULLETFIRECOMMAND_H
#define PLAYERBULLETFIRECOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include <SFML/Audio.hpp>

using namespace sf;

class PlayerBullet;

class PlayerBulletFireCommand :
	public ObjectCommand
{

private:
	PlayerBullet* context = NULL;
	float distTravelled = 0.0f;
	SoundBuffer sBuf;
	Sound fireSound;
	

public:
	PlayerBulletFireCommand(PlayerBullet* context);
	PlayerBulletFireCommand(const PlayerBulletFireCommand& obj);
	~PlayerBulletFireCommand();
	PlayerBulletFireCommand& operator=(const PlayerBulletFireCommand& obj);

	void execute(float elapsedTime);

};

#endif

