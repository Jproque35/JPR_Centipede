#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#pragma once
#include "GameObject.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "CentipedeMoveEvent.h"
#include "PlayerInputEvent.h"
#include "BulletFiredEvent.h"
#include "MushroomHitEvent.h"
#include "CentipedeHitEvent.h"
#include "BulletCollideEvent.h"

class GameObjectFactory
{

public:
	static GameObject* makeObject(ObjectType type, float initX, float initY);

};

#endif

