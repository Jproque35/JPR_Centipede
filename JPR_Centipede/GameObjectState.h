#ifndef GAMEOBJECTSTATE_H
#define GAMEOBJECTSTATE_H
#pragma once
#include <vector>
#include <queue>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StateTypes.h"
#include <unordered_map>
#include "CommandType.h"

using namespace sf;
using namespace std;

class GameEventListener;
class ObjectCommand;

class GameObjectState
{

protected:
	StateType type;
	vector<GameEventListener*> events;

public:
	virtual ~GameObjectState();

	virtual void init();
	StateType getType() const;
	void clearEventListeners();
	void addEventListener(GameEventListener* event);
	virtual void executeEventListeners(float elapsedTime) = 0;
	virtual void update(float elapsedTime) = 0;

};

#endif

