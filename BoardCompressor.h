#pragma once

#include <string>
#include "BoardGame.h"
using namespace std;

class BoardCompressor {

    virtual void compress(string)=0;
    virtual string extract()=0;
};
