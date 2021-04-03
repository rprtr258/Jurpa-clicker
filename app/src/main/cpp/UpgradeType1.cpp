#include "UpgradeType1.h"

bool isClickedOnSprite(sf::Sprite &sprite, const sf::RenderWindow &window);

UpgradeType1::UpgradeType1() {
}

UpgradeType1::UpgradeType1(int cost, sf::Texture texture) {
    this->texture=texture;
    this->cost=cost;
    sprite.setTexture(this->texture);
    sprite.setPosition(16, 413);
    setPopup();
}

void UpgradeType1::setPopup() {
    std::wostringstream sstream;
    sstream << L"Апгрейд \"Мудрый горностай\"\nCost: " << cost << L"\nУдешевляет все здания на 10%";
    popup.setContent(sstream.str());
}

void UpgradeType1::effect(GameState &gameState) {
    for(int i=0;i<BUILDS_COUNT;i++) {
        gameState.getBuildingsArray()[i].setCost(gameState.getBuildingsArray()[i].getCost()/10*9);
    }
}

int UpgradeType1::getCost() {
    return cost;
}

void UpgradeType1::setCost(int newCost) {
    this->cost = newCost;
    setPopup();
}

void UpgradeType1::setTexture(sf::Texture tex) {
    texture=tex;
    sprite.setTexture(this->texture);
    sprite.setPosition(16,413);
}

sf::Sprite &UpgradeType1::getSprite() {
    return sprite;
}

void UpgradeType1::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    if(isClickedOnSprite(sprite, window)) {
        popup.show();
        popup.draw(window,sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
    }
}
