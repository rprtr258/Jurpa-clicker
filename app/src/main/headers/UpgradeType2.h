#ifndef UPGRADETYPE2_H
#define UPGRADETYPE2_H

#include <SFML/Graphics.hpp>

#include "Building.h"
#include "InfoPopup.h"
#include "GameState.h"
#include "GameConstants.h"

class UpgradeType2 {
    public:
        UpgradeType2();
        UpgradeType2(int cost, sf::Texture texture);
        ~UpgradeType2();

        void effect(GameState &gameState);
        void setPopup();

        int getCost();
        void setCost(int newCost);

        void setTexture(sf::Texture tex);

        void setJPS(int *jps);

        void draw(sf::RenderWindow &window);
        sf::Sprite &getSprite();
    private:
        int cost;
        int *jps;
        sf::Texture texture;
        sf::Sprite sprite;
        InfoPopup popup;
};

#endif
