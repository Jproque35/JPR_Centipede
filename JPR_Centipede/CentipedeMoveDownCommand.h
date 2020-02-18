#ifndef CENTIPEDEMOVEDOWNCOMMAND_H
#define CENTIPEDEMOVEDOWNCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "Centipede.h"
class CentipedeMoveDownCommand :
	public ObjectCommand
{

private:
	Centipede* context = NULL;
	Vector2f initPos;

public:
	CentipedeMoveDownCommand(Centipede* context);
	void execute(float elapsedTime);

};

#endif

