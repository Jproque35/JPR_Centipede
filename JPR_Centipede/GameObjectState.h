#ifndef GAMEOBJECTSTATE_H
#define GAMEOBJECTSTATE_H
#pragma once
#include <vector>
#include <queue>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StateTypes.h"

using namespace sf;
using namespace std;

class GameEventListener;
class ObjectCommand;

class GameObjectState
{

protected:
	StateType type;
	vector<GameEventListener*> events;
	queue<ObjectCommand*> commands;

public:
	virtual ~GameObjectState();

	GameObjectState* copy(const GameObjectState& obj);
	StateType getType() const;
	int getNumCommands() const;
	void clearEventListeners();
	void clearCommands();
	void addEventListener(GameEventListener* event);
	void queueCommand(ObjectCommand* command);
	virtual void executeEventListeners(float elapsedTime) = 0;
	virtual void executeCommand(float elapsedTime) = 0;
	virtual void update(float elapsedTime) = 0;

};

#endif

