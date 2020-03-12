#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H
#pragma once
#include "ObjectData.h"
#include <sstream>

using namespace std;

class ScoreManager
{

private:
	static ScoreManager* instance;
	Text hud;
	Font font;
	int score = 0;
	ScoreManager();
	ScoreManager(const ScoreManager& obj);
	~ScoreManager();
	ScoreManager& operator=(const ScoreManager& obj);

public:
	static ScoreManager* getInstance();
	static void resetInstance();

	int getScore();
	void increaseScore(int i);
	void setScore(int i);
	void updateScoreText();
	Text getScoreText();

};

#endif

