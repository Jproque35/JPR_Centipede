#ifndef PLAYERBULLETSTATE_H
#define PLAYERBULLETSTATE_H
#pragma once
#include "GenericState.h"

class PlayerBullet;

class PlayerBulletState : public GenericState {

private:
	PlayerBullet* context;
	float range = 10.0f;
	float distTravelled = 0.0f;

public:
	PlayerBulletState(PlayerBullet* context);
	PlayerBulletState(const PlayerBulletState& obj);
	~PlayerBulletState();
	PlayerBulletState& operator=(const PlayerBulletState& obj);

	void update(float elapsedTime);

};


#endif
