#pragma once
using namespace std;

#include "CommonSearcher.h"
#include "HeuristicSearcher.h"
#include <map>


template <class T>
class AStar : public CommonSearcher<T>, public HeuristicSearcher<T> {

public:
    AStar(Heuristic<T>& h) : HeuristicSearcher<T>(h){};
    virtual MazeSolution<T> search(Searchable<T> &s) {

        auto init = s.getStartState();
        auto goal = s.getGoalState();

        this->_openList.push(init);
        this->setCostSoFar(init, 0);

        while (!this->_openList.empty()) {
            auto best = this->_openList.top();

            this->_openList.pop();

            auto adj = s.getAllPossibleStates(best);
            for (auto &a : adj) {
                if (a == goal) {
                    a.setCameFrom(best);
                    return MazeSolution<T>(this->backTrace(&a, s));
                }

                if (this->getIsInClosed(a))
                    continue;

                double newCost = this->getInCostSoFar(best) + this->getCostBetweenTwoStates(best, a);

                if ((!this->getIsInCostSoFar(a)) || (newCost < this->getInCostSoFar(a))) {
                    this->setCostSoFar(a, newCost);
                    int cost = newCost + this->getH().getCost(goal, a);
                    a.setCost(cost);
                    a.setCameFrom(best);
                    this->_openList.push(a);
                }
            }
            this->_closedList.push_back(best);
        }
        throw NoMazeSolutionException();
    };
};