#pragma once

#include "../Solution/MazeSolution.h"
#include "../Searchables/Searchable.h"
template <class T>
class Searcher
{
public:
    virtual MazeSolution<T> search(Searchable<T>& s) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};

