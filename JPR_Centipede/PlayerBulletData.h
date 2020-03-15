#ifndef BULLETDATA_H
#define BULLETDATA_H
#pragma once
#include "ObjectData.h"

class PlayerBulletData : public ObjectData
{

	friend class PlayerBulletFireCommand;

public:
	PlayerBulletData(float initX, float initY);
	PlayerBulletData(const PlayerBulletData& obj);
	~PlayerBulletData();
	PlayerBulletData& operator=(const PlayerBulletData& obj);

	void init(float xPos, float yPos);
};

#endif

