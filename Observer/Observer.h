#pragma once
#include <string>
#include "../Games/Maze.h"

class Observable;

class Observer
{
public:
    virtual void update(Observable& o, string&) = 0;
    virtual void update(Observable& o, string&, string&) = 0;
    virtual void update(Observable& o, const Maze&) = 0;
    virtual void update(Observable& o, MazeSolution<pair<int, int>>* solution) = 0;
    virtual void update(Observable& o, vector<string>) = 0;
    virtual void update(Observable& o, vector<vector<string>>&) = 0;
};