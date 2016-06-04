#include "InfoPopup.h"
InfoPopup::InfoPopup() {
    visible=false;
    font.loadFromFile("times.ttf");
    this->content.setFont(font);
    this->content.setCharacterSize(20);
    this->content.setColor(sf::Color::Black);
    texture.loadFromFile("images/info_popup.png");
    sprite.setTexture(texture);
}

InfoPopup::InfoPopup(std::wstring content) {
    visible=false;
    font.loadFromFile("times.ttf");
    this->content.setString(content);
    this->content.setFont(font);
    this->content.setCharacterSize(20);
    this->content.setColor(sf::Color::Black);
    texture.loadFromFile("images/info_popup.png");
    sprite.setTexture(texture);
}

const std::wstring InfoPopup::getContent() {
    return content.getString();
}

void InfoPopup::setContent(std::wstring text) {
    content.setString(text);
}

void InfoPopup::show() {
    visible=true;
}

void InfoPopup::hide() {
    visible=false;
}

void InfoPopup::draw(sf::RenderWindow &window, const int x, const int y) {
    if(visible) {
        sprite.setPosition(x,y-texture.getSize().y);
        content.setPosition(sprite.getPosition().x+30,sprite.getPosition().y+10);
        window.draw(sprite);
        window.draw(content);
    }
}
