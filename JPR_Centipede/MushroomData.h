#ifndef MUSHROOMDATA_H
#define MUSHROOMDATA_H
#pragma once
#include "ObjectData.h"

using namespace sf;

class MushroomData :
	public ObjectData
{
	friend class Mushroom;

private:
	int health = 4;

public:
	MushroomData(float initX, float initY);
	MushroomData(const MushroomData &obj);
	~MushroomData();
	MushroomData& operator=(const MushroomData &obj);

	int getHealth() const;
	void setHealth(int i);
	void decrementHealth();

};

#endif

