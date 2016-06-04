#include "SaveLoader.h"

SaveLoader::SaveLoader() {
    saveReaderStream = new std::ifstream();
    saveWriterStream = new std::ofstream();
}

SaveLoader::~SaveLoader() {
    delete saveReaderStream;
    delete saveWriterStream;
}

GameState& SaveLoader::loadGame() {
    BuildingsInfo& buildingsInfo = gameState.getBuildingsArray();
    int tempCookies, tempDeadCookies, tempJPS, tempJurpsPerClick;

    encode();
    saveReaderStream->open("save.txt");
    (*saveReaderStream) >> tempCookies >> tempDeadCookies >> tempJPS >> tempJurpsPerClick;
    gameState.setCookies(tempCookies);
    gameState.setDeadCookies(tempDeadCookies);
    gameState.setJPS(tempJPS);
    gameState.setJurpsPerClick(tempJurpsPerClick);
    for (int i=0;i<BUILDS_COUNT;i++) {
        int ownedTemp, costTemp, gainTemp;
        std::string textureFileTemp;
        char space;
        (*saveReaderStream) >> ownedTemp >> costTemp >> gainTemp;
        saveReaderStream->get(space);
        std::getline((*saveReaderStream),textureFileTemp);
        buildingsInfo.addNewBuilding(costTemp, ownedTemp, gainTemp, textureFileTemp);
    }
    for (int i=0;i<UPGRADES_COUNT;i++) {
        int tempUpgradeCost;
        (*saveReaderStream) >> tempUpgradeCost;
        gameState.getUpgradesCostArray()[i] = tempUpgradeCost;
    }
    saveReaderStream->close();
    encode();

    return gameState;
}

void SaveLoader::saveGame() {
    encode();
    saveWriterStream->open("save.txt");
    (*saveWriterStream) << gameState.getCookies() << ' ' << gameState.getDeadCookies() << ' ' << gameState.getJPS() << ' ' << gameState.getJurpsPerClick() << std::endl;
    for (int i=0;i<BUILDS_COUNT;i++) { //запись зданий
        (*saveWriterStream) <<
        gameState.getBuildingsArray().getBuilding(i).getOwned() << ' ' <<
        gameState.getBuildingsArray().getBuilding(i).getCost()  << ' ' <<
        gameState.getBuildingsArray().getBuilding(i).getGain()  << ' ' <<
        gameState.getBuildingsArray().getBuilding(i).getFile()  << std::endl;
    }
    for (int i=0;i<UPGRADES_COUNT;i++) {
        (*saveWriterStream) << gameState.getUpgradesCostArray()[i] << std::endl;
    }
    saveWriterStream->close();
    encode();
}

void SaveLoader::encode() {
    std::ifstream in("save.txt");
    char c;
    int k = 0;
    char s[500];
    while(!in.eof()) {
        c=in.get();
        s[k]=c;
        k++;
    }
    in.close();

    std::ofstream out("save.txt");
    for(int i=0;i<k-1;i++) {
        out.put((char)~s[i]);
    }
    out.close();
}
