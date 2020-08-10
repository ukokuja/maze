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
    virtual Solution<T> search(const Searchable<T> &s) = 0;

    virtual int getNumberOfNodesEvaluated() { return _evaluatedNodes; };

//Additional implementation
public:
    State<T> &popOpenList() {
        _evaluatedNodes++;
        return _openList.top();
    }
    vector<unique_ptr<State<T>>>& backTrace(State<T>& state, Searchable<T>& searchable) {
        auto* trace = new list<State<T>>;

        while (state != searchable->getStartState()){
            if(state == nullptr){
                cout<<"no path"<<endl;
                return nullptr;
            }
            trace->push_back(make_unique(state));
            state = state.getCameFrom();
        }
        trace->push_back(make_unique(searchable.getStartState()));
        return trace;
    }

protected:
    int _evaluatedNodes;
    priority_queue<State<T>> _openList;
};

