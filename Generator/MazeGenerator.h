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
                board[i][j] = enc[FREE];
            }
            for (int j = 1; j < size; j+=2) {
                board[i][j] = enc[WALL];
            }
        }
        for (int i = 1; i < size; i+=2) {
            board[i] = vector<string>(size);
            for (int j = 0; j < size; j++) {
                board[i][j] = enc[WALL];
            }

        }
        return board;
    }
};