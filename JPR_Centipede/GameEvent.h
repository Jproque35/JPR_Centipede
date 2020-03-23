#ifndef GAMEEVENTLISTENER_H
#define GAMEEVENTLISTENER_H
#pragma once
#include <iostream>

using namespace std;

class GameObject;

class GameEventListener
{

public:
	virtual ~GameEventListener();
	virtual GameEventListener* recontextCopy(GameObject* obj) = 0;
	virtual void update(float elapsedTime) = 0;

};
#endif

