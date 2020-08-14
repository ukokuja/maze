#pragma once

#include "BoardCompressor.h"
#include "../Games/Maze.h"

class MazeCompressor : public BoardCompressor {
    virtual void compress (Maze& maze) {

    }

    virtual Maze* extract () {

    }
};