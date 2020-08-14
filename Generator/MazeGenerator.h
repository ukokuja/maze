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
    virtual std::string measureAlgorithmTime(int size) {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        generate(size);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        return "Maze generated! It took " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()) + "μs";
    }
    virtual vector<vector<string>> initMaze (int size) {
        vector<vector<string>> board = vector<vector<string>>(size);
        for (int i = 0; i < size; i+=2) {
            board[i] = vector<string>(size);
            for (int j = 0; j < size; j+=2) {
                board[i][j] = FREE;
            }
            for (int j = 1; j < size; j+=2) {
                board[i][j] = WALL;
            }
        }
        for (int i = 1; i < size; i+=2) {
            board[i] = vector<string>(size);
            for (int j = 0; j < size; j++) {
                board[i][j] = WALL;
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