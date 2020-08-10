//
// Created by Lucas Kujawski on 06/08/2020.
//

#ifndef MAZE_MAZE2D_H
#define MAZE_MAZE2D_H
#include <string>
#include <vector>
#include <chrono>
#include "Position.h"
#include "SolutionAlgorithm.h"
#include "CreationAlgorithm.h"
#include "Searchable.h"

class Maze2d : public Searchable {

public:
    void solve(SolutionAlgorithm* a);
};

class Maze2dGenerator {
    CreationAlgorithm* _c;
public:
    Maze2dGenerator(CreationAlgorithm* c) : _c(c){};
    virtual Maze2d generate ()=0; //decide the params
    virtual std::string measureAlgorithmTime()=0; //decide the params
};

class AbstractMaze2dGenerator : public Maze2dGenerator {
public:
    virtual std::string measureAlgorithmTime(CreationAlgorithm* c) {

        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        generate();
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        return "Time difference = " + std::to_string(std::chrono::duration_cast<std::chrono::seconds>(end - begin).count());
     }
};
class SimpleMaze2dGenerator : public AbstractMaze2dGenerator {
public:
    SimpleMaze2dGenerator(CreationAlgorithm*);
    virtual Maze2d generate () {

    }
};
class MyMaze2dGenerator : public AbstractMaze2dGenerator {
public:
    MyMaze2dGenerator(CreationAlgorithm*);
    virtual Maze2d generate () {

    }
};
#endif //MAZE_MAZE2D_H
