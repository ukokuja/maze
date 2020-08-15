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

private:
    vector<Observer*> m_observers;
};