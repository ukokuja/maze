#pragma once

#include <set>
#include "CommonSearcher.h"

template<class T>
class BFS : public CommonSearcher<T> {
private:
    list<State<T>> _blacks;
    list<State<T>> _grays;
public:
    virtual Solution<T> search(Searchable<T> &s) {
        this->_openList.push(s.getStartState());
        while (!this->_openList.empty()) {
            auto state = this->popOpenList();
            if (s.getGoalState() == state) {
                return Solution<T>(this->backTrace(&state, s));
            }
            _grays.push_back(state);
            auto adj = s.getAllPossibleStates(state);

            for (auto &a : adj) {
                bool isWhite = count_if(_grays.begin(), _grays.end(), [a](auto g) { return a == g; }) < 1;

                if (isWhite) {
                    _grays.push_back(a);
                    a.setCameFrom(state);
                    this->_openList.push(a);
                }
            }

            _blacks.push_back(state);
        }
        return Solution<T>();
    };
};
