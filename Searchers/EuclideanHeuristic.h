//
// Created by Lucas Kujawski on 15/08/2020.
//

#pragma once


#include "Heuristic.h"
#include "../States/State.h"

template <class T>
class EuclideanHeuristic : public Heuristic<T> {
public:
    double getCost(State<T>& a, State<T>& b) {
        return sqrt(pow((a.getState().first - b.getState().first), 2) + pow((a.getState().second - b.getState().second), 2));
    }
};



