#include "UpgradeType2.h"
bool isClickedOnSprite(sf::Sprite &sprite, const sf::RenderWindow &window);
UpgradeType2::UpgradeType2() {
}

UpgradeType2::UpgradeType2(int cost, sf::Texture texture) {
    this->texture=texture;
    this->cost=cost;
    sprite.setTexture(this->texture);
    sprite.setPosition(16 + this->texture.getSize().x,413);
    setPopup();
}

UpgradeType2::~UpgradeType2() {
    delete jps;
}

void UpgradeType2::setPopup() {
    std::wostringstream sstream;
    sstream << L"Апгрейд \"Быстрая мушка\"\nCost: " << cost << L"\nУвеличивает количество журп \nза клик на 30% от жпс\nЖурп за клик: " << (*jps);
    popup.setContent(sstream.str());
}

void UpgradeType2::effect(GameState &gameState) {
    gameState.setJurpsPerClick(gameState.getJPS()/10*3 + gameState.getJurpsPerClick());
}

void UpgradeType2::setJPS(int *jps) {
    this->jps = jps;
}

int UpgradeType2::getCost() {
    return cost;
}

void UpgradeType2::setCost(int newCost) {
    this->cost=newCost;
    setPopup();
}

void UpgradeType2::setTexture(sf::Texture tex) {
    this->texture=tex;
    sprite.setTexture(this->texture);
    sprite.setPosition(16 + this->texture.getSize().x,413);
}

sf::Sprite &UpgradeType2::getSprite() {
    return sprite;
}

void UpgradeType2::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    if(isClickedOnSprite(sprite, window)) {
        popup.show();
        popup.draw(window,sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
    }
}
