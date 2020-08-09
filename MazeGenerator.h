#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "Maze.h"
#include "MazeSearchable.h"


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

    }
};

class SpecialMazeGenerator : public MazeGenerator {
public:
    virtual Maze* generate (int size) {

    }
};