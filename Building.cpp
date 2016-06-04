#include "Building.h"
Building::Building() {
    this->cost=100;
    this->owned=0;
    this->gain=4;
    this->textureFile = "images\\build_1.png";
    this->texture.loadFromFile(textureFile);
    setText(costText ,"Costs: ",cost );
    setText(ownedText,"Owned: ",owned);
    setText(gainText ,"Gains: ",gain );
}

Building::Building(int cost, int owned, int gain) {
    this->cost=cost;
    this->owned=owned;
    this->gain=gain;

    setText(costText ,"Costs: ",cost );
    setText(ownedText,"Owned: ",owned);
    setText(gainText ,"Gains: ",gain );
}

Building::Building(const Building &other) {
    cost=other.cost;
    owned=other.owned;
    gain=other.gain;
    yshift = other.yshift;
    textureFile = other.textureFile;
    texture.loadFromFile(textureFile);
    sprite.setTexture(texture);

    setText(costText ,"Costs: ",cost );
    setText(ownedText,"Owned: ",owned);
    setText(gainText ,"Gains: ",gain );
}

const Building& Building::operator=(const Building& other) {
    cost=other.cost;
    owned=other.owned;
    gain=other.gain;
    yshift = other.yshift;
    textureFile = other.textureFile;
    texture.loadFromFile(textureFile);
    sprite.setTexture(texture);

    setText(costText ,"Costs: ",cost );
    setText(ownedText,"Owned: ",owned);
    setText(gainText ,"Gains: ",gain );
    return other;
}

void Building::moveY(int yshift) {
    this->yshift+=yshift;
    sprite.setPosition   (   sprite.getPosition().x,   sprite.getPosition().y+yshift);
    costText.setPosition ( costText.getPosition().x, costText.getPosition().y+yshift);
    ownedText.setPosition(ownedText.getPosition().x,ownedText.getPosition().y+yshift);
    gainText.setPosition ( gainText.getPosition().x, gainText.getPosition().y+yshift);
}
void Building::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(costText);
    window.draw(ownedText);
    window.draw(gainText);
}
void Building::setTextPosition(sf::Text &text, const sf::Font &font,int xshift, int yshift) {
    text.setPosition(sprite.getPosition().x+xshift,sprite.getPosition().y+yshift);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setColor(sf::Color::Black);
}
void Building::setText(sf::Text &text,const char *str, int number) {
    std::ostringstream sstream;
    sstream << str << number;
    text.setString(sstream.str());
}

void Building::setTexture(sf::Texture texture) {
    this->texture=texture;
    this->sprite.setTexture(this->texture);
}

void Building::setWindow(const sf::RenderWindow &window) {
    sprite.setPosition(window.getSize().x-texture.getSize().x,yshift);
}

void Building::setFont(const sf::Font &font) {
    setTextPosition(costText ,font,84,25);
    setTextPosition(ownedText,font,84,45);
    setTextPosition(gainText ,font,84,65);
}

void Building::setYshift(const int yshift) {
    this->yshift=yshift;
}

int Building::getX() {
    return sprite.getPosition().x;
}

int Building::getGain() {
    return gain;
}

void Building::setGain(int gain) {
    this->gain = gain;
    setText(gainText,"Gain: ", gain);
}

std::string Building::getFile() {
    return textureFile;
}

void Building::setFile(std::string file) {
    textureFile = file;
    texture.loadFromFile(textureFile);
    setTexture(texture);
}

int Building::getOwned() {
    return owned;
}

void Building::setOwned(int owned) {
    this->owned=owned;
    setText(ownedText,"Owned: ", owned);
}

int Building::getCost() {
    return cost;
}

void Building::setCost(int costArg) {
    if(costArg<=0) {
        cost=1;
    } else {
        cost=costArg;
    }
    setText(costText,"Costs: ",cost);
}
