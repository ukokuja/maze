#pragma once

#include "Searchable.h"
#include "Maze.h"

template<class T>
class MazeSearchable : public Searchable<T> {
public:
    MazeSearchable(Maze &maze) : _maze(maze) {};

public:
    //ADD implementation for those methodes
    virtual State<T> &getStartState() { return _maze.getStart(); };

    virtual State<T> &getGoalState() { return _maze.getEnd(); };

    virtual std::vector<State<T>> getAllPossibleStates(State<T> &s) { _maze.calculateStates(); };

private:
    Maze _maze;
};

