#pragma once
using namespace std;
#include <string>
#include "../Searchables/Searchable.h"
#include "../Searchers/Searcher.h"
#include "../Games/Maze.h"
#include "../Searchables/MazeSearchable.h"
#include "../States/MazeState.h"

//Interface for BoardGenerator
class BoardGenerator {
public:
    BoardGenerator() {};
    //Given a size, it generates a square maze
    virtual const Maze generate (int size)=0;

    //It returns the time that takes to generate a maze with a specific size
    virtual string measureAlgorithmTime(int)=0;
};


class MazeGenerator : public BoardGenerator {
public:
    virtual string measureAlgorithmTime(int size) {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        generate(size);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        return "Maze generated! It took " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()) + "μs";
    }
    //Initialize a maze board full with walls.
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

    //Initialize a maze board full with walls.
    virtual vector<vector<string>> initEmptyMaze (int size) {
        vector<vector<string>> board = vector<vector<string>>(size);
        for (int i = 0; i < size; i++) {
            board[i] = vector<string>(size);
            for (int j = 0; j < size; j++) {
                board[i][j] = enc[WALL];
                if (j < size - 1) {
                    board[i][j] = enc[FREE];
                }
                if (i == size - 1) {
                    board[i][j] = enc[WALL];
                }
            }

        }
        return board;
    }
};