#ifndef GAMEEVENTLISTENER_H
#define GAMEEVENTLISTENER_H
#pragma once
#include <iostream>

using namespace std;

class GameEventListener
{

public:
	virtual ~GameEventListener();
	virtual void update(float elapsedTime) = 0;

};
#endif

