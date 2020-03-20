#ifndef FIREPRESSEDEVENT_H
#define FIREPRESSEDEVENT_H
#pragma once
#include "GameEvent.h"

class FirePressedEvent
	: public GameEventListener
{

public:
	FirePressedEvent();
	FirePressedEvent(const FirePressedEvent& obj);
	~FirePressedEvent();
	FirePressedEvent& operator=(const FirePressedEvent& obj);

	void update(float elapsedTime);

};

#endif
