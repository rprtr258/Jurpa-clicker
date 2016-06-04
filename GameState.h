#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "BuildingsInfo.h"

class GameState {
    public:
        GameState();
        ~GameState();
        BuildingsInfo& getBuildingsArray();
        int *getUpgradesCostArray();

        int getJPS();
        void setJPS(int newJPS);

        int getCookies();
        void setCookies(int newCookies);

        int getDeadCookies();
        void setDeadCookies(int newDeadCookies);

        int& getJurpsPerClick();
        void setJurpsPerClick(int newJurpsPerClick);
    private:
        BuildingsInfo buildingsInfo;
        int *upgradesCost;
        int jurpsPerClick, jps, cookies, deadCookies;
};

#endif
