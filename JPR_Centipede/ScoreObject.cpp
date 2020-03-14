#include "ScoreObject.h"

ScoreManager* ScoreManager::instance = 0;

ScoreManager::ScoreManager() {

    this->font.loadFromFile("game_over.ttf");

    this->scoreText.setPosition(Vector2f(0.0f, 0.0f));
    this->scoreText.setFont(this->font);
    this->scoreText.setCharacterSize(75);
    this->scoreText.setFillColor(sf::Color::White);
    this->scoreText.setOutlineColor(sf::Color::Black);
    this->scoreText.setOutlineThickness(1.0f);
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
    scoreText.setString(ss.str());

}

int ScoreManager::getScore() const {

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

Text ScoreManager::getScoreText() const {

    return this->scoreText;

}