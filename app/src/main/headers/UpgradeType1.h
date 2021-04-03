#ifndef UPGRADETYPE1_H
#define UPGRADETYPE1_H

#include <sstream>

#include <SFML/Graphics.hpp>

#include "Building.h"
#include "InfoPopup.h"
#include "GameState.h"
#include "GameConstants.h"

class UpgradeType1 {
    public:
        UpgradeType1();
        UpgradeType1(int cost, sf::Texture texture);

        void effect(GameState &gameState);
        void setPopup();

        int getCost();
        void setCost(int newCost);

        void setTexture(sf::Texture tex);

        void draw(sf::RenderWindow &window);
        sf::Sprite &getSprite();
    private:
        int cost;
        sf::Texture texture;
        sf::Sprite sprite;
        InfoPopup popup;
};

#endif
