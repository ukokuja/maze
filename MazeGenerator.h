#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "Maze.h"
#include "MazeSearchable.h"
#include "MazeState.h"


class MazeGeneratorInterface {
public:
    MazeGeneratorInterface() {};
    virtual Maze* generate (int size)=0; //decide the params
    virtual std::string measureAlgorithmTime(int)=0; //decide the params
};

class MazeGenerator : public MazeGeneratorInterface {
public:
    virtual std::string measureAlgorithmTime(int size) {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        generate(size);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        return "Time difference = " + std::to_string(std::chrono::duration_cast<std::chrono::seconds>(end - begin).count());
    }
};


class SimpleMazeGenerator : public MazeGenerator {
public:

    virtual Maze* generate (int size) {
        srand (time(NULL));
        int startX = rand() % size;
        int startY = rand() % size;
        int endX = rand() % size;
        int endY = rand() % size;
        int currX = 0;
        int currY = 0;
        vector<vector<int>> board;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = FREE;
            }
        }
//        while (currX != endX && currY != endY) {
//
//        }
        MazeState start(make_pair(startX, startY));
        MazeState end(make_pair(endX, endY));
        return new Maze(board, size, start, end);
    }
};

class SpecialMazeGenerator : public MazeGenerator {
public:
    virtual Maze* generate (int size) {

    }
};