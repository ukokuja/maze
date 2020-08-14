#pragma once
using namespace std;
#include "../Searchers/BFS.h"
#include "../Searchers/AStar.h"
#include "Factory.h"

template <class T>
class SearcherFactory : public Factory<Searcher<T>*> {
public:
    virtual Searcher<T>* get(string& name) {
        if (name == "BFS") {
            return new BFS<T>;
        } else if (name == "AStar") {
            return new AStar<T>;
        }
        return nullptr;
    }

};