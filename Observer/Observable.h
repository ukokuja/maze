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
        m_observers.push_back(&observer);
    }
    void notify(string message)
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
            (*it)->update(*this, message);
    }

    void notify(const Maze& m)
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
            (*it)->update(*this, m);
    }

    void notify(vector<vector<string>>& v)
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
            (*it)->update(*this, v);
    }

    void notify(Solution<pair<int, int>>* solution)
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
            (*it)->update(*this, solution);
    }

    void notify(vector<string> list)
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
            (*it)->update(*this, list);
    }

    void notify(int n)
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
            (*it)->update(*this, n);
    }


private:
    vector<Observer*> m_observers;
};