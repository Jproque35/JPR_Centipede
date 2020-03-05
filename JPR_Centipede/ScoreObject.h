#ifndef HUDOBJECT_H
#define HUDOBEJCT_H
#pragma once
#include "ObjectData.h"
#include <sstream>

using namespace std;

class ScoreObject
{

private:
	Text hud;
	Font font;
	int score = 0;

public:
	ScoreObject();
	int getScore();
	void increaseScore(int i);
	void setScore(int i);
	void updateHud();
	Text getHudText();

};

#endif

