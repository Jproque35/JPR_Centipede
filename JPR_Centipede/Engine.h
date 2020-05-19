#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>;
#include <vector>
#include <queue>
#include <sstream>

using namespace sf;
using namespace std;

class GameObjectManager;
class InputManager;
class ScoreManager;
class EventManager;
class FontManager;
class SpriteManager;
class SoundManager;
class GameObjectFactory;
class CollisionMap;
class Centipede;
class CentipedeManager;
class ScreenManager;
class Screen;

class Engine {

private:
	static Engine* instance;

	GameObjectManager* gm = NULL;
	InputManager* im = NULL;
	ScoreManager* scm = NULL;
	EventManager* em = NULL;
	FontManager* fm = NULL;
	SpriteManager* spm = NULL;
	SoundManager* sdm = NULL;
	GameObjectFactory* objFactory = NULL;
	CollisionMap* cm = NULL;
	CentipedeManager* centiMngr = NULL;

	ScreenManager* screenManager;
	Screen* currScreen;

	RenderWindow window;

	Text hudText;

	Engine();
	Engine(const Engine& obj) = delete;
	~Engine();
	Engine& operator=(const Engine& obj) = delete;

	void init();
	void initObjects();
	void initPlayer();
	void initEnemies();
	void initMushrooms();
	void initEvents();

public:
	static Engine* getInstance();
	static void resetInstance();
	void start();

};

#endif