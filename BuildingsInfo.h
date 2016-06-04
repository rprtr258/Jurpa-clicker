#ifndef BUILDINGSINFO_H
#define BUILDINGSINFO_H

#include <SFML/Graphics.hpp>

#include "Building.h"
#include "GameConstants.h"

class BuildingsInfo {
    public:
        BuildingsInfo();
        ~BuildingsInfo();
        void addNewBuilding(int cost, int owned, int gain, std::string textureFile);
        Building& getBuilding(int num);
        Building& operator[](const int &n);
        void sortByCost();
        void sortByOwned();
        void sortByGain();
    private:
        Building data[BUILDS_COUNT];
        int ptr;
};

#endif
