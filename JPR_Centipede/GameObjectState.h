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
	queue<ObjectCommand*> commands;
	unordered_map<CommandType, ObjectCommand*> cmdTbl;
	ObjectCommand* currCommand;

public:
	virtual ~GameObjectState();
	GameObjectState* copy(const GameObjectState& obj);
	StateType getType() const;
	int getNumCommands() const;
	void clearEventListeners();
	void clearCommands();
	void addEventListener(GameEventListener* event);
	void setCommandType(CommandType type);
	void queueCommand(ObjectCommand* command);
	virtual void executeEventListeners(float elapsedTime) = 0;
	virtual void executeCommand(float elapsedTime) = 0;
	virtual void update(float elapsedTime) = 0;

};

#endif

