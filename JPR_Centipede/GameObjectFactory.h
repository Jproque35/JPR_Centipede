#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#pragma once
#include "GameObject.h"
#include "Player.h"
#include "PlayerInputEvent.h"

class GameObjectFactory
{

public:
	GameObject* makeObject(ObjectType type, GameObjectManager gm, int initX, int initY);

};

#endif

