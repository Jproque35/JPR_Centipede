#ifndef CENTIPEDEMOVERIGHTCOMMAND_H
#define CENTIPEDEMOVERIGHTCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "Centipede.h"
class CentipedeMoveRightCommand :
	public ObjectCommand
{

private:
	Centipede* context = NULL;
	Vector2f initPos;

public:
	CentipedeMoveRightCommand(Centipede* context);
	void execute(float elapsedTime);

};

#endif

