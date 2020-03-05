#include "ScoreObject.h"

ScoreObject::ScoreObject() {

    this->font;
    this->font.loadFromFile("game_over.ttf");

    this->hud.setPosition(Vector2f(0.0f, 0.0f));
    this->hud.setFont(this->font);
    this->hud.setCharacterSize(75);
    this->hud.setFillColor(sf::Color::White);
    this->hud.setOutlineColor(sf::Color::Black);
    this->hud.setOutlineThickness(1.0f);
    this->updateHud();

}

void ScoreObject::updateHud() {

    stringstream ss;
    ss << "Score: " << this->score;
    hud.setString(ss.str());

}

int ScoreObject::getScore() {

    return this->score;

}

void ScoreObject::increaseScore(int i) {

    this->score += i;
    this->updateHud();

}

void ScoreObject::setScore(int i) {

    this->score = i;
    this->updateHud();
}

Text ScoreObject::getHudText() {

    return this->hud;

}