#include "GameScreen.h"
#include "GameObjectManager.h"
#include "ScoreObject.h"
#include "InputManager.h"
#include "GameObjectFactory.h"
#include "EventManager.h"
#include "SpriteManager.h"
#include "SoundManager.h"
#include "FontManager.h"
#include "CentipedeManager.h"
#include "CollisionMap.h"

GameScreen::GameScreen() {


}

GameScreen::GameScreen(const GameScreen& obj) {}

GameScreen::~GameScreen() {

	GameObjectManager::resetInstance();
	InputManager::resetInstance();
	ScoreManager::resetInstance();
	SoundManager::resetInstance();
	SpriteManager::resetInstance();
	GameObjectFactory::resetInstance();
	EventManager::resetInstance();
	CentipedeManager::resetInstance();
	CollisionMap::resetInstance();

}

GameScreen& GameScreen::operator=(const GameScreen& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}