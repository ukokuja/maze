#pragma once
#include <string>
#include "../Searchables/Searchable.h"
#include "../Searchers/Searcher.h"
#include "../Games/Maze.h"
#include "../Searchables/MazeSearchable.h"
#include "../States/MazeState.h"


class MazeGeneratorInterface {
public:
    MazeGeneratorInterface() {};
    virtual const Maze generate (int size)=0; //decide the params
    virtual std::string measureAlgorithmTime(int)=0; //decide the params
};

class MazeGenerator : public MazeGeneratorInterface {
public:
    map<char, int> D = { {'N',1}, {'S',2}, {'E',4}, {'W',8}};
    map<char, int> DX = { {'N',0}, {'S',0}, {'E',1}, {'W',-1}};
    map<char, int> DY = { {'N',-1}, {'S',1}, {'E',0}, {'W',0}};
    map<char, char> OP = { {'N','S'}, {'S','N'}, {'E','W'}, {'W','E'}};

public:
    virtual std::string measureAlgorithmTime(int size) {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        generate(size);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        return "Time difference = " + std::to_string(std::chrono::duration_cast<std::chrono::seconds>(end - begin).count());
    }
    virtual vector<vector<char>> initMaze (int size) {
        vector<vector<char>> board = vector<vector<char>>(size);
        for (int i = 0; i < size; i++) {
            board[i] = vector<char>(size);
            for (int j = 0; j < size; j++) {
                board[i][j] = 0;
            }
        }
        return board;
    }
};


class SimpleMazeGenerator : public MazeGenerator {
public:

    virtual const Maze generate (int size) {
        int startX = rand() % size;
        int startY = rand() % size;
        int endX = rand() % size;
        int endY = rand() % size;
        int currX = 0;
        int currY = 0;
        auto board = initMaze(size);
//        while (currX != endX && currY != endY) {
//
//        }
        MazeState start(startX, startY, nullptr);
        MazeState end(endX, endY, nullptr);
        return Maze(board, size, start, end);
    }
};
