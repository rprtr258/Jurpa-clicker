#include <iostream>
#include <cstdlib>

#include "GameConstants.h"
#include "Building.h"
#include "GameState.h"
#include "BuildingsInfo.h"
#include "SaveLoader.h"
#include "UpgradeType2.h"
#include "UpgradeType1.h"
#include "Util.h"

int main() {
    srand(time(NULL));
    SaveLoader saveLoader;
    GameState &gameState = saveLoader.loadGame();
    int yshift=30;
    BuildingsInfo &buildings = gameState.getBuildingsArray(); //������ ������
    sf::Texture ev;
    ev.loadFromFile("images/null_event.png");
    int eventShits = 56;
    sf::Sprite falling[eventShits];
    for(int i=0;i<eventShits;i++) {
        falling[i].setTexture(ev);
        falling[i].setRotation(rand() % 360);
        falling[i].setPosition(rand() % (416 - ev.getSize().x), -3000 + rand() % 3000);
    }

    UpgradeType1 up1;
    UpgradeType2 up2;

    {
        sf::Texture textureTemp;
        textureTemp.loadFromFile("images/upgrade_1.png");
        up1.setTexture(textureTemp);
        up1.setCost(gameState.getUpgradesCostArray()[0]);

        up2.setJPS(&gameState.getJurpsPerClick());
        textureTemp.loadFromFile("images/upgrade_2.png");
        up2.setTexture(textureTemp);
        up2.setCost(gameState.getUpgradesCostArray()[1]);
    }


    char title[100]; //��������� ����
    sf::Clock clock; //������

    sprintf(title, "Current jurps:\n%d", gameState.getCookies()); //��������� � ����������� ����
    sf::RenderWindow mainWindow(sf::VideoMode(800, 600), title, sf::Style::Titlebar|sf::Style::Close); //����
    sf::RectangleShape plainBack(sf::Vector2f(800.f, 600.f)); //���
    plainBack.setFillColor(sf::Color(102, 0, 153)); //��������� ����� ����

    sf::Texture tex_cookie, sortButtons;
    sortButtons.loadFromFile("images/menu.png");
    tex_cookie.loadFromFile("images/cookie.png");
    sf::Sprite spr_cookie(tex_cookie), sortSprite(sortButtons);
    sortSprite.setPosition(mainWindow.getSize().x - sortButtons.getSize().x, 0);
    spr_cookie.setPosition(57, 177);

    sf::Font font;
    font.loadFromFile("times.ttf");

    for (int i = 0;i < BUILDS_COUNT;i++) { //��������� ������
        buildings[i].setYshift(yshift + 104 * i);
        buildings[i].setWindow(mainWindow);
        buildings[i].setFont(font);
    }

    sf::Text tex_jurps(title, font, 25); //�������� ������ ��� ������
    tex_jurps.setPosition(64, 60);
    tex_jurps.setColor(sf::Color(181,230,29));

    sf::Text tex_jps(title, font, 25); //�������� ������ ��� ��� ������
    tex_jps.setPosition(64,120);
    tex_jps.setColor(sf::Color(181,230,29));
    setText(tex_jps,"JPS: ",gameState.getJPS());
    sf::Event event;
    while (mainWindow.isOpen()) { //���� ���� �������
        while (mainWindow.pollEvent(event)) { //��������� �������
            if (event.type == sf::Event::Closed) { //���� �������� ����
                mainWindow.close(); //������� ����
            }
            if (event.type == sf::Event::MouseWheelMoved) {
                const int movespeed = 20; //�������� ���������
                if(event.mouseWheel.delta == 1) { //�������� �����
                    unsigned int ndown = yshift - movespeed + 104 * BUILDS_COUNT;
                    if(ndown >= mainWindow.getSize().y) {
                        yshift -= movespeed;
                        for (int i = 0;i < BUILDS_COUNT;i++) { //��������� ������
                            buildings[i].moveY(-movespeed);
                        }
                    }
                    if(ndown < mainWindow.getSize().y - 30) {
                        yshift = mainWindow.getSize().y - 30 - 104 * BUILDS_COUNT;
                    }
                } else { //�������� ����
                    if(yshift < 30) {
                        yshift += movespeed;
                        if(yshift > 30) {
                            yshift = 30;
                        }
                        for (int i = 0;i <BUILDS_COUNT;i++) { //��������� ������
                            buildings[i].moveY(movespeed);
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) { //���� ������ �����
                if (event.mouseButton.button == sf::Mouse::Left) { //���� ������ ����� ������
                    if(isClickedOnSprite(spr_cookie,mainWindow)) { //�� �����
                        gameState.setCookies(gameState.getCookies() + gameState.getJurpsPerClick()); //����������� ����
                        setJurpsText(title,gameState.getCookies(),tex_jurps,mainWindow);
                    }
                    if(isClickedOnRectangle(buildings[0].getX(), 0, mainWindow.getSize().x, 30, mainWindow)) {
                        int lpos = buildings[0].getX();
                        if(isClickedOnRectangle(lpos, 0, lpos + 94, 30, mainWindow)) {
                            buildings.sortByCost();
                        } else if(isClickedOnRectangle(lpos + 95, 0, lpos + 191, 30, mainWindow)) {
                            buildings.sortByOwned();
                        } else if(isClickedOnRectangle(lpos + 192, 0, lpos + 287, 30, mainWindow)) {
                            buildings.sortByGain();
                        } else if(isClickedOnRectangle(lpos + 288, 0, lpos + 383, 30, mainWindow)) {
                            std::cout << "clicked fourth\n";
                        }
                    } else if(isClickedOnRectangle(buildings[0].getX(), 30,
                            mainWindow.getSize().x,yshift + 104 * BUILDS_COUNT, mainWindow)) {
                        int num = (event.mouseButton.y - yshift) / 104;
                        if(gameState.getCookies()>=buildings[num].getCost()) {
                            buildings[num].setOwned(buildings[num].getOwned()+1);
                            gameState.setJPS(gameState.getJPS() + buildings[num].getGain());
                            gameState.setCookies(gameState.getCookies()-buildings[num].getCost());
                            gameState.setDeadCookies(gameState.getDeadCookies() + buildings[num].getCost() / 5);
                            buildings[num].setCost((buildings[num].getCost() + 2) / 3 * 4);
                            setText(tex_jps,"JPS: ",gameState.getJPS());
                            setJurpsText(title,gameState.getCookies(),tex_jurps,mainWindow);
                        }
                    }
                    if(isClickedOnSprite(up1.getSprite(),mainWindow)) {
                        if(gameState.getCookies() >= up1.getCost()) {
                            gameState.setCookies(gameState.getCookies() - up1.getCost());

                            up1.effect(gameState);
                            up1.setCost((up1.getCost()  + 1)* 3 / 2);
                            gameState.getUpgradesCostArray()[0] = up1.getCost();

                            setText(tex_jps,"JPS: ",gameState.getJPS());
                            setJurpsText(title,gameState.getCookies(),tex_jurps,mainWindow);
                        }
                    }
                    if(isClickedOnSprite(up2.getSprite(),mainWindow)) {
                        if(gameState.getCookies()>=up2.getCost()) {
                            gameState.setCookies(gameState.getCookies() - up2.getCost());

                            up2.effect(gameState);
                            up2.setCost(up2.getCost() * 3 / 2);
                            gameState.getUpgradesCostArray()[1] = up2.getCost();
                            setText(tex_jps,"JPS: ",gameState.getJPS());
                            setJurpsText(title,gameState.getCookies(),tex_jurps,mainWindow);
                        }
                    }
                }
            }
        }
        if (clock.getElapsedTime().asSeconds() >= 1) { //����������� ���
            gameState.setCookies(gameState.getCookies() + gameState.getJPS()*clock.getElapsedTime().asMilliseconds() / 1000);
            clock.restart();
            setJurpsText(title,gameState.getCookies(),tex_jurps,mainWindow);
        }

        mainWindow.clear(); //������� ����
        mainWindow.draw(plainBack); //��������� ����
        for(int i = 0;i < eventShits;i++) {
            mainWindow.draw(falling[i]);
            falling[i].setPosition(falling[i].getPosition().x, falling[i].getPosition().y + 0.4);
            if(falling[i].getPosition().y > 772) {
                falling[i].setPosition(rand() % (416 - ev.getSize().x), -3000 + rand() % 3000);
                falling[i].setRotation(rand() % 360);
            }
        }
        mainWindow.draw(spr_cookie); //��������� �����
        mainWindow.draw(tex_jurps); //��������� ������
        mainWindow.draw(tex_jps); //��������� ������ ���
        for (int i = 0;i < BUILDS_COUNT;i++) {
            buildings[i].draw(mainWindow);
        }

        up2.draw(mainWindow);
        up1.draw(mainWindow);

        mainWindow.draw(sortSprite); //��������� ������ � �����������

        mainWindow.display(); //����������� ������
    }
    saveLoader.saveGame();
    return 0;
}
