#ifndef HUDOBJECT_H
#define HUDOBEJCT_H
#pragma once
#include "ObjectData.h"
#include <sstream>

using namespace std;

class HudObject
{

private:
	Text hud;
	Font font;
	int score = 0;

public:
	HudObject();
	int getScore();
	void increaseScore(int i);
	void setScore(int i);
	void updateHud();
	Text getHudText();

};

#endif

