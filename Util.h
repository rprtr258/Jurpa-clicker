#ifndef UTIL_H
#define UTIL_H

#include <sstream>
#include <fstream>

#include <SFML/Graphics.hpp>

void setText(sf::Text &text, const char *str, const int number) {
    std::ostringstream sstream;
    sstream << str << number;
    text.setString(sstream.str());
}

void setJurpsText(char* title, const int cookies, sf::Text &text, sf::Window &window) {
    std::sprintf(title, "Current jurps:\n%d", cookies);
    text.setString(title);
    window.setTitle(title);
}

bool isClickedOnRectangle(const int x1, const int y1, const int x2, const int y2, const sf::Window &window) {
    sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
    if (mouseCoords.x<=x2 && mouseCoords.x>=x1 &&
        mouseCoords.y<=y2 && mouseCoords.y>=y1) {
        return true;
    }
    return false;
}

bool isClickedOnSprite(sf::Sprite &sprite, const sf::RenderWindow &window) {
    const sf::Vector2f &spriteCoords = sprite.getPosition();
    const sf::Vector2u  &textureSize = sprite.getTexture()->getSize();
    if(isClickedOnRectangle(spriteCoords.x,spriteCoords.y,spriteCoords.x+textureSize.x,spriteCoords.y+textureSize.y,window)) {
        return true;
    }
    return false;
}

#endif
