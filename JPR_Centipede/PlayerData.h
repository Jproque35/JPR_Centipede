#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#pragma once
#include "ObjectData.h"

class PlayerData :
	public ObjectData
{

public:
	PlayerData(float initX, float initY);
	PlayerData(const PlayerData& obj);
	~PlayerData();
	PlayerData& operator=(const PlayerData& obj);

	void init(float xPos, float yPos);
};

#endif

