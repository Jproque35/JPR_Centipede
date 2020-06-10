#ifndef FIREPRESSEDEVENT_H
#define FIREPRESSEDEVENT_H
#pragma once
#include "GameEvent.h"
#include <SFML/Audio.hpp>

using namespace sf;

class FirePressedEvent
	: public GameEventListener
{

private:
	Sound bulletSound;

	FirePressedEvent(const FirePressedEvent& obj) = delete;
	FirePressedEvent& operator=(const FirePressedEvent& obj) = delete;

public:
	FirePressedEvent();
	~FirePressedEvent();

	void update(float elapsedTime);

};

#endif
