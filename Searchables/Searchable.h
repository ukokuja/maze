#pragma once

#include <vector>
#include "../States/State.h"
using namespace std;
template <class T>
class Searchable
{
public:
    virtual const State<T>& getStartState() const = 0;
    virtual const State<T>& getGoalState() const = 0;
    virtual vector<State<T>> getAllPossibleStates(State<T>& s) = 0;
};

