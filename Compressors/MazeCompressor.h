#pragma once

#include "../Games/Maze.h"
#include "BoardCompressor.h"

class MazeCompressor : public BoardCompressor {
public:
    virtual ifstream& compress(Maze& b, ifstream& stream) {

        return stream;
    }
    virtual Maze* extract() {
        return nullptr;
    }
};