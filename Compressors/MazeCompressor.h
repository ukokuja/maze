#pragma once

#include <fstream>
#include "BoardCompressor.h"
#include "../Games/Maze.h"
class MazeCompressor : public BoardCompressor {
public:
    virtual ostream& compress(Maze& m, ostream& stream) {
        BoardCompressor::compress(m, stream);
        auto metadata =  m.getMetaData();
        stream << metadata;
        return stream;
    }
    virtual Maze* extract(istream& stream) {
        auto board = BoardCompressor::extract(stream);
        string line;
        int meta[4];
        for (int i = 0; i < 4; i++) {
            getline(stream, line, OUTER_DELIMITER);
            meta[i] = stoi(line);
        }
        MazeState end(meta[0], meta[1]);
        MazeState start(meta[2], meta[3]);
        return new Maze(*board, end, start);
    }
};