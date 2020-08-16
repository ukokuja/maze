//
// Created by Lucas Kujawski on 15/08/2020.
//

#pragma once

#include <list>
#include <iostream>
#include <map>
#include "Heuristic.h"

template <class T>
class HeuristicSearcher {
public:
    HeuristicSearcher(Heuristic<T>& h) : _h(h){};

    bool getIsInClosed(const State<T>& a) {
        return count_if(_closedList.begin(), _closedList.end(), [a](auto g) {return a == g;}) > 0;
    }
    bool getIsInCostSoFar (State<T>& a) {
        return count_if(_costSoFar.begin(), _costSoFar.end(), [a](auto g) {
            return a.getState().first == g.first.getState().first && a.getState().second == g.first.getState().second;
        }) > 0;
    }
    double getCostBetweenTwoStates (State<T>& a, State<T>& b) {
        return sqrt(pow((a.getState().first - b.getState().first), 2) + pow((a.getState().second - b.getState().second), 2));
    }
public:
    const list<State<T> *> &getClosedList() const {
        return _closedList;
    }

    const map<State<T>, double> &getCostSoFar() const {
        return _costSoFar;
    }

    void setClosedList(const list<State<T> *> &closedList) {
        _closedList = closedList;
    }

    const double& getInCostSoFar(State<T>& s) {
        return _costSoFar[s];
    }

    void setCostSoFar(State<T>& s, double cost) {
        _costSoFar[s] = cost;
    }

    Heuristic<T> &getH() const {
        return _h;
    }

    void setH(Heuristic<T> &h) {
        _h = h;
    }

protected:
    Heuristic<T>& _h;
    list<State<T>> _closedList;
protected:
    map<State<T>, double> _costSoFar;
};

