#pragma once

#include <vector>
#include "State.h"
using namespace std;
template <class T>
class Searchable
{
public:
    virtual State<T>& getStartState() = 0;
    virtual State<T>& getGoalState() = 0;
    virtual vector<State<T>> getAllPossibleStates(State<T>& s) = 0;
};

