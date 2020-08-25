#pragma once
using namespace std;
#include "../Searchers/BFS.h"
#include "../Searchers/AStar.h"
#include "../Searchers/ManhattanHeuristic.h"
#include "../Searchers/EuclideanHeuristic.h"
#include "Factory.h"

template <class T>
class SearcherFactory : public Factory<Searcher<T>*> {
public:
    //Returns a Searcher by name
    virtual Searcher<T>* get(string& name) {
        if (name == "BFS") {
            return new BFS<T>;
        } else if (name == "AStarManhattan") {
            ManhattanHeuristic<T>* manhattanHeuristic = new ManhattanHeuristic<T>();
            return new AStar<T>(*manhattanHeuristic);
        } else if (name == "AStarEuclidean") {
            EuclideanHeuristic<T>* euclideanHeuristic = new EuclideanHeuristic<T>();
            return new AStar<T>(*euclideanHeuristic);
        }
        return nullptr;
    }

};