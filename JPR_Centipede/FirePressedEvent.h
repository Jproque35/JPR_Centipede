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
	SoundBuffer sBuf;
	Sound bulletSound;

public:
	FirePressedEvent();
	FirePressedEvent(const FirePressedEvent& obj);
	~FirePressedEvent();
	FirePressedEvent& operator=(const FirePressedEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif
