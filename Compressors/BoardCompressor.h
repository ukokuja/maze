#pragma once

#include <string>
#include "../Games/BoardGame.h"
using namespace std;

class BoardCompressor {
public:
    virtual ifstream& compress(BoardGame&, ifstream& stream){
        return stream;
    };
    virtual BoardGame* extract(){
        return nullptr;
    };
};
