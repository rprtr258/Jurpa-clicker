#include "GameState.h"

GameState::GameState() {
    upgradesCost = new int[UPGRADES_COUNT];
}

GameState::~GameState() {
}

BuildingsInfo& GameState::getBuildingsArray() {
    return buildingsInfo;
}

int GameState::getJPS() {
    return jps;
}

void GameState::setJPS(int newJPS) {
    jps=newJPS;
}

int GameState::getCookies() {
    return cookies;
}

void GameState::setCookies(int newCookies) {
    cookies=newCookies;
}

int GameState::getDeadCookies() {
    return deadCookies;
}

void GameState::setDeadCookies(int newDeadCookies) {
    deadCookies = newDeadCookies;
}

int& GameState::getJurpsPerClick() {
    return jurpsPerClick;
}

void GameState::setJurpsPerClick(int newJurpsPerClick) {
    jurpsPerClick=newJurpsPerClick;
}

int *GameState::getUpgradesCostArray() {
    return upgradesCost;
}
