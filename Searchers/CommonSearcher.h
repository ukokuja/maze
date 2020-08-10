#pragma once

#include "Searcher.h"
#include <queue>
#include <list>
using namespace std;
template<class T>
class CommonSearcher : public Searcher<T> {
public:
    CommonSearcher() : _evaluatedNodes(0) {}

//Abstraction
public:
    virtual Solution<T> search(Searchable<T> &s) = 0;

    virtual int getNumberOfNodesEvaluated() { return _evaluatedNodes; };

//Additional implementation
public:
    const State<T> &popOpenList() {
        _evaluatedNodes++;
        return _openList.top();
    }
    vector<State<T>> backTrace(State<T>& state, Searchable<T>& searchable) {
        vector<State<T>> trace;
        State<T>* currentState = &state;
        while (*currentState != searchable.getStartState()){
            if(*currentState == nullptr){
                cout<<"no path"<<endl;
                break;
            }
            trace.push_back(state);
            currentState = state.getCameFrom();
        }
        trace.push_back(searchable.getStartState());
        return trace;
    }

protected:
    int _evaluatedNodes;
    priority_queue<State<T>> _openList;
};

