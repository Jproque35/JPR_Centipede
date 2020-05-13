#ifndef RESPAWNSCREEN_H
#define RESPAWNSCREEN_H
#pragma once
#include "Screen.h"

class RespawnScreen :
	public Screen
{

private:
	float counter = 0.0f;

protected:
	void input(float dtAsSecods);
	void update(float dtAsSeconds);
	void draw();

	RespawnScreen(const RespawnScreen& obj) = delete;
	RespawnScreen& operator=(const RespawnScreen& obj) = delete;

public:
	RespawnScreen();
	~RespawnScreen();
	virtual void init(RenderWindow& w) override;

};

#endif
