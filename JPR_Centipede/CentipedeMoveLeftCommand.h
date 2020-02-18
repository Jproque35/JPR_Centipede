#ifndef CENTIPEDEMOVELEFTCOMMAND_H
#define CENTIPEDEMOVELEFTCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "Centipede.h"

class CentipedeMoveLeftCommand :
	public ObjectCommand
{

private:
	Centipede* context = NULL;
	Vector2f initPos;

public:
	CentipedeMoveLeftCommand(Centipede* context);
	void execute(float elapsedTime);

};

#endif

