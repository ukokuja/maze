//
// Created by Lucas Kujawski on 15/08/2020.
//

#pragma once


#include "Heuristic.h"
#include "../States/State.h"

template <class T>
class ManhattanHeuristic : public Heuristic<T> {
public:
    double getCost(State<T>& a, State<T>& b) {
        return abs(a.getState().first - b.getState().first) + abs(a.getState().second - b.getState().second);
    }
};



