//
// Created by Lucas Kujawski on 06/08/2020.
//

#ifndef MAZE_SOLUTIONALGORITHM_H
#define MAZE_SOLUTIONALGORITHM_H


#include "Position.h"

class SolutionAlgorithm {

};
class BFS : public SolutionAlgorithm {

};
class Heuristic : public SolutionAlgorithm {
    Position _state;
    Position _goal;

};

class AirDistanceHeuristic : public Heuristic {};
class ManhattanDistanceHeuristic : public Heuristic {};



class AStar : public BFS {
    Heuristic* _h;
public:
    AStar(Heuristic* h) {
        _h = h;
    }
};

#endif //MAZE_SOLUTIONALGORITHM_H
