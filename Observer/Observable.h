#pragma once

#include "Observer.h"
#include "../Games/Maze.h"
#include <vector>
using namespace std;

class Observable
{
public:
    void addObserver(Observer& observer)
    {
        _observers.push_back(&observer);
    }
    void notify(string key)
    {
        for (auto it = _observers.begin(); it != _observers.end(); ++it)
            (*it)->update(*this, key);
    }

    void notify(string key, string name)
    {
        for (auto it = _observers.begin(); it != _observers.end(); ++it)
            (*it)->update(*this, key, name);
    }

    void notify(const Maze& m)
    {
        for (auto it = _observers.begin(); it != _observers.end(); ++it)
            (*it)->update(*this, m);
    }

    void notify(vector<vector<string>>& v)
    {
        for (auto it = _observers.begin(); it != _observers.end(); ++it)
            (*it)->update(*this, v);
    }

    void notify(MazeSolution<pair<int, int>>* solution)
    {
        for (auto it = _observers.begin(); it != _observers.end(); ++it)
            (*it)->update(*this, solution);
    }

    void notify(vector<string> list)
    {
        for (auto it = _observers.begin(); it != _observers.end(); ++it)
            (*it)->update(*this, list);
    }

private:
    vector<Observer*> _observers;
};