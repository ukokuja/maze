#pragma once

#include <fstream>
#include "../Games/Maze.h"
#include "BoardCompressor.h"

class MazeCompressor : public BoardCompressor {
public:
    virtual ofstream& compress(Maze& b, ofstream& stream) {
        stream << b.getData();
        return stream;
    }
    virtual Maze* extract() {
        return nullptr;
    }
};