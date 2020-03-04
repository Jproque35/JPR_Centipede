#ifndef OBJECTCOMMAND_H
#define OBJECTCOMMAND_H
#pragma once
#include <iostream>

enum class CommandType {
	Unknown,
	Generic,
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Activate,
	Deactivate,
	SetPosition,
	ShootBullet
};

using namespace std;

class ObjectCommand
{

protected:
	bool finished = false;
	CommandType type = CommandType::Generic;

public:
	bool isFinished();
	CommandType getType();
	virtual void execute(float elapsedTime) = 0;

};

#endif

