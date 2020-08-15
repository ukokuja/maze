#pragma once
#include <string>
#include "../Games/Maze.h"

class Observable;

class Observer
{
public:
    virtual void update(Observable& o, string&) = 0;
    virtual void update(Observable& o, const Maze&) = 0;
};