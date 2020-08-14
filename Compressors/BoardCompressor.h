#pragma once

#include <string>
#include "../Games/BoardGame.h"
using namespace std;

class BoardCompressor {

    virtual void compress(BoardGame&)=0;
    virtual BoardGame* extract()=0;
};
