#ifndef BUILDING_H
#define BUILDING_H

#include <sstream>
#include <string>

#include <SFML/Graphics.hpp>

class Building {
    public:
        Building();
        Building(int cost, int owned, int gain);
        Building(const Building &other);

        void setTexture(sf::Texture texture);
        void setWindow(const sf::RenderWindow &window);
        void setFont(const sf::Font &font);
        void setYshift(const int yshift);

        int getCost();
        void setCost(int cost);

        int getOwned();
        void setOwned(int owned);

        int getGain();
        void setGain(int gain);

        std::string getFile();
        void setFile(std::string file);

        void draw(sf::RenderWindow &window);
        void moveY(int yshift);
        int getX();
        const Building& operator=(const Building& other);
    private:
        void setText(sf::Text &text,const char *str, int number);
        void setTextPosition(sf::Text &text, const sf::Font &font, int xshift, int yshift);

        int cost, owned, gain, yshift;
        std::string textureFile;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Text costText,ownedText,gainText;
};
#endif
