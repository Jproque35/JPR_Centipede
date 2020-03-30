#ifndef CENTIPEDEMANAGER_H
#define CENTIPEDEMANAGER_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace sf;
using namespace std;

class Centipede;
class GameObjectFactory;

class CentipedeManager {

private:
	static CentipedeManager* instance;
	int maxActive = 10, currActive = 0;
	GameObjectFactory* objFactory;

	CentipedeManager();
	CentipedeManager(const CentipedeManager& obj) = delete;
	~CentipedeManager();
	CentipedeManager& operator=(const CentipedeManager& obj) = delete;

public:
	static CentipedeManager* getInstance();
	static void resetInstance();
	int getNumActive() const;
	void setNumActive(int i);
	int getMaxActive() const;
	vector<Centipede*> generateCentipede(int length);

};

#endif
