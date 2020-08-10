#pragma once

#include <set>
#include "CommonSearcher.h"
template <class T>
class BFS : public CommonSearcher<T>
{
private:
    set<State<T>> _blacks;
    set<State<T>> _grays;
public:
    virtual Solution<T> search(Searchable<T>& s)
    {
        this->_openList.push(s.getStartState());


        while (!this->_openList.empty()) {
            auto state = this->popOpenList();
            if (s.getGoalState() == state) {
                return Solution<T>(this->backTrace(state, s));
            }
            auto adj = s.getAllPossibleStates(state);

            for (auto &a : adj) {
                bool isWhite = (_grays.find(a) == _grays.end());

                if (isWhite) {
                    _grays.insert(a);
                    a.setCameFrom(state);
                    this->_openList.push(a);
                }
            }

            _blacks.insert(state);
        }
        return Solution<T>();
    };
};
