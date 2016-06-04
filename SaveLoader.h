#ifndef SAVELOADER_H
#define SAVELOADER_H

#include <fstream>
#include <string>

#include "GameConstants.h"
#include "Building.h"
#include "GameState.h"

class SaveLoader {
    public:
        SaveLoader();
        ~SaveLoader();
        GameState& loadGame();
        void saveGame();
        void encode();
    private:
        std::ifstream *saveReaderStream;
        std::ofstream *saveWriterStream;
        GameState gameState;
};

#endif
