//
// Created by Lucas Kujawski on 07/08/2020.
//

#ifndef MAZE_DEMO_H
#define MAZE_DEMO_H


#include <iostream>
#include "Maze2d.h"
#include "SolutionAlgorithm.h"

class Demo {
public:
    void run() {
        MyMaze2dGenerator generator;
        Maze2d maze = generator.generate();
        std::cout << maze << std::endl;

        maze.solve(new BFS());
        maze.solve(new AStar(ManhattanHeuristic()));


    }
};


#endif //MAZE_DEMO_H
