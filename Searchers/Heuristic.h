#pragma once
#include "../States/State.h"
template <class T>
class Heuristic {
public:
    virtual double getCost(State<T>& a, State<T>& b)=0;
};



