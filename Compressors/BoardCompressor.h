#pragma once

#include <string>
#include "../Games/BoardGame.h"
using namespace std;

class BoardCompressor {
public:
    virtual ofstream& compress(BoardGame&, ofstream& stream){
        return stream;
    };
    virtual BoardGame* extract(){
        return nullptr;
    };
};
