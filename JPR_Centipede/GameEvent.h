#ifndef GAMEEVENTLISTENER_H
#define GAMEEVENTLISTENER_H
#pragma once
#include "CommandFactory.h"
#include <iostream>

using namespace std;

class GameEventListener
{

public:
	virtual void update(float elapsedTime) = 0;

};
#endif

