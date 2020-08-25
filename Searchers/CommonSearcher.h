#pragma once

#include "Searcher.h"
#include <queue>
#include <list>
using namespace std;

class NoMazeSolutionException : public std::exception {};

template<class T>
class CommonSearcher : public Searcher<T> {
public:
    CommonSearcher() : _evaluatedNodes(0) {}

public:
    virtual MazeSolution<T> search(Searchable<T> &s) = 0;

public:
    virtual int getNumberOfNodesEvaluated() { return _evaluatedNodes; };
    const State<T> &popOpenList() {
        _evaluatedNodes++;
        _openList.pop();
        return _openList.top();
    }
    const vector<State<T>> backTrace(const State<T>* state, Searchable<T>& searchable) {
        vector<State<T>> trace;
        while (*state != searchable.getStartState() && state != state->getCameFrom()){
            if(*state == nullptr){
                throw NoMazeSolutionException();
            }
            trace.push_back(*state);
            state = state->getCameFrom();
        }
        trace.push_back(searchable.getStartState());
        return trace;
    }

protected:
    int _evaluatedNodes;
    priority_queue<State<T>> _openList;
};

