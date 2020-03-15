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
	Text scoreText;
	Font font;
	int score = 0;

	ScoreManager();
	ScoreManager(const ScoreManager& obj) = delete;
	~ScoreManager();
	ScoreManager& operator=(const ScoreManager& obj) = delete;

public:
	static ScoreManager* getInstance();
	static void resetInstance();

	int getScore() const;
	void increaseScore(int i);
	void setScore(int i);
	void updateScoreText();
	Text getScoreText() const;

};

#endif

