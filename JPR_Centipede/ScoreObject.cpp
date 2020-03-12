#include "ScoreObject.h"

ScoreManager* ScoreManager::instance = 0;

ScoreManager::ScoreManager() {

    this->font.loadFromFile("game_over.ttf");

    this->hud.setPosition(Vector2f(0.0f, 0.0f));
    this->hud.setFont(this->font);
    this->hud.setCharacterSize(75);
    this->hud.setFillColor(sf::Color::White);
    this->hud.setOutlineColor(sf::Color::Black);
    this->hud.setOutlineThickness(1.0f);
    this->updateScoreText();

}

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

void ScoreManager::updateScoreText() {

    stringstream ss;
    ss << "Score: " << this->score;
    hud.setString(ss.str());

}

int ScoreManager::getScore() {

    return this->score;

}

void ScoreManager::increaseScore(int i) {

    this->score += i;
    this->updateScoreText();

}

void ScoreManager::setScore(int i) {

    this->score = i;
    this->updateScoreText();
}

Text ScoreManager::getScoreText() {

    return this->hud;

}