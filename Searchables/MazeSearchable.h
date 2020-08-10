#pragma once

#include "Searchable.h"
#include "../Games/Maze.h"

class MazeSearchable : public Searchable<pair<int,int>> {
public:
    MazeSearchable(const Maze& maze) : _maze(maze) {
        cout << "hi";
    };

public:
    //ADD implementation for those methodes
    virtual const MazeState &getStartState() const { return _maze.getStart(); };

    virtual const MazeState &getGoalState() const  { return _maze.getEnd(); };

    virtual vector<State<pair<int,int>>> getAllPossibleStates(State<pair<int,int>> &s) { return _maze.calculateStates(s); };

private:
    const Maze& _maze;
};

