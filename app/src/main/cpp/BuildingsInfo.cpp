#include "BuildingsInfo.h"

BuildingsInfo::BuildingsInfo() {
    ptr = 0;
}

BuildingsInfo::~BuildingsInfo() {
    ;
}

void BuildingsInfo::addNewBuilding(int cost, int owned, int gain, std::string textureFile) {
    data[ptr].setCost(cost);
    data[ptr].setOwned(owned);
    data[ptr].setGain(gain);
    data[ptr].setFile(textureFile);
    ptr++;
}

Building& BuildingsInfo::getBuilding(int num) {
    return data[num];
}

Building& BuildingsInfo::operator[](const int &n) {
    return data[n];
}

void BuildingsInfo::sortByCost() {
    for(int i=0;i<BUILDS_COUNT;i++) {
        for(int j=i;j<BUILDS_COUNT;j++) {
            if(data[i].getCost()>data[j].getCost()) {
                Building temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
void BuildingsInfo::sortByOwned() {
    for(int i=0;i<BUILDS_COUNT;i++) {
        for(int j=i;j<BUILDS_COUNT;j++) {
            if(data[i].getOwned()<data[j].getOwned()) {
                Building temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
void BuildingsInfo::sortByGain() {
    for(int i=0;i<BUILDS_COUNT;i++) {
        for(int j=i;j<BUILDS_COUNT;j++) {
            if(data[i].getGain()>data[j].getGain()) {
                Building temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
