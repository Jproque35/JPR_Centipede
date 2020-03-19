#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#pragma once
#include <vector>

using namespace std;

class GameEventListener;

class EventManager
{

private:
	static EventManager* instance;
	vector<GameEventListener*> events;

	EventManager();
	EventManager(const EventManager& obj) = delete;
	~EventManager();
	EventManager& operator=(const EventManager& obj) = delete;

public:
	static EventManager* getInstance();
	static void resetInstance();
	void addEvent(GameEventListener* event);
	void update(float elapsedTime);

};

#endif

