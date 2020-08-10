#pragma once

#include "Searchable.h"
#include "Maze.h"

class MazeSearchable : public Searchable<pair<int,int>> {
public:
    MazeSearchable(Maze &maze) : _maze(maze) {};

public:
    //ADD implementation for those methodes
    virtual State<pair<int,int>> &getStartState() { return _maze.getStart(); };

    virtual State<pair<int,int>> &getGoalState() { return _maze.getEnd(); };

    virtual std::vector<State<pair<int,int>>> getAllPossibleStates(State<pair<int,int>> &s) { _maze.calculateStates(s); };

private:
    Maze _maze;
};

