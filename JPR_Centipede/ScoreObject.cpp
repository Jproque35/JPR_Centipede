#include "ScoreObject.h"

HudObject::HudObject() {

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

void HudObject::updateHud() {

    stringstream ss;
    ss << "Score: " << this->score;
    hud.setString(ss.str());

}

int HudObject::getScore() {

    return this->score;

}

void HudObject::increaseScore(int i) {

    this->score += i;
    this->updateHud();

}

void HudObject::setScore(int i) {

    this->score = i;
    this->updateHud();
}

Text HudObject::getHudText() {

    return this->hud;

}