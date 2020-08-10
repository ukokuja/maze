#pragma once

#include "../Solution.h"
#include "../Searchables/Searchable.h"
template <class T>
class Searcher
{
public:
    virtual Solution<T> search(Searchable<T>& s) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};

