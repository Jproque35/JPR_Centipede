#include "ScoreObject.h"

ScoreManager* ScoreManager::instance = 0;

ScoreManager::ScoreManager() {}

ScoreManager::~ScoreManager() {}

ScoreManager* ScoreManager::getInstance() {

    if (!instance) {

        instance = new ScoreManager();

    }

    return instance;

}

void ScoreManager::resetInstance() {

    delete(instance);
    instance = NULL;

}

int ScoreManager::getScore() const {

    return this->score;

}

int ScoreManager::getLives() const {

    return this->lives;

}

void ScoreManager::increaseScore(int i) {

    this->score += i;

}

void ScoreManager::setScore(int i) {

    this->score = i;

}

void ScoreManager::setLives(int i) {

    this->lives = i;

}