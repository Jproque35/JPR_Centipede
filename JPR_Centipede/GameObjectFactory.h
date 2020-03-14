#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#pragma once
#include "GameObject.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "CentipedeMoveEvent.h"
#include "CentipedeHeadState.h"
#include "PlayerInputEvent.h"
#include "BulletFiredEvent.h"
#include "MushroomHitEvent.h"
#include "BulletCollideEvent.h"
#include "CentipedeBodyState.h"
#include "CentipedeMoveEvent.h"
#include "CentipedeHitEvent.h"

class GameObjectFactory
{

public:
	static GameObject* makeObject(ObjectType type, float initX, float initY);

};

#endif

