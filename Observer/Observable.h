#pragma once

#include "Observer.h"
#include <vector>
using namespace std;

class Observable
{
public:
    void addObserver(Observer& observer)
    {
        m_observers.push_back(&observer);
    }
    void notify()
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
            (*it)->update(*this);
    }

private:
    vector<Observer*> m_observers;
};