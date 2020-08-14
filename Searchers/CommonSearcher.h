#pragma once

#include "Searcher.h"
#include <queue>
#include <list>
using namespace std;
template<class T>
class CommonSearcher : public Searcher<T> {
public:
    CommonSearcher() : _evaluatedNodes(0) {}

public:
    virtual Solution<T> search(Searchable<T> &s) = 0;

public:
    virtual int getNumberOfNodesEvaluated() { return _evaluatedNodes; };
    const State<T> &popOpenList() {
        _evaluatedNodes++;
        _openList.pop();
        return _openList.top();
    }
    vector<State<T>> backTrace(const State<T>* state, Searchable<T>& searchable) {
        vector<State<T>> trace;
        while (*state != searchable.getStartState() && state != state->getCameFrom()){
            if(*state == nullptr){
                throw "no path";
            }
            trace.push_back(*state);
//            cout << "-> (" << state->getState().first << ", " << state->getState().second  << ")" << endl;
            state = state->getCameFrom();
        }
        trace.push_back(searchable.getStartState());
        return trace;
    }

protected:
    int _evaluatedNodes;
    priority_queue<State<T>> _openList;
};

