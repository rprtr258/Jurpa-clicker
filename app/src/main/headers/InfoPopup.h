#ifndef INFOPOPUP_H
#define INFOPOPUP_H

#include <string>
#include <SFML/Graphics.hpp>

class InfoPopup {
    public:
        InfoPopup();
        InfoPopup(std::wstring content);
        const std::wstring getContent();
        void setContent(std::wstring text);
        void show();
        void hide();
        void draw(sf::RenderWindow &window, const int x, const int y);
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Text content;
        sf::Font font;
        bool visible;
};

#endif
