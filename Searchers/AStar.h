#pragma once

#include "CommonSearcher.h"
#include <map>
template <class T>
class AStar : public CommonSearcher<T>
{

public:
    virtual Solution<T> search(Searchable<T>& s)
    {/*
        list<State<T>*> openList;
        //list of nodes that have been checked
        list<State<T>*> closedList;
        map<State<T>*, double> toState;

        State<T>* init = s->getInitialState();
        State<T>* goal = s->getGoalState();

        openList.push_back(init);
        toState[init]=0;

        while(!openList.empty()){
            // greedy choice
            State<T>* best= openList.front();
            for(auto &o : openList){
                if(this->fromHere(o,goal)+toState.at(o)<this->fromHere(best,goal)+toState.at(best)){
                    best=o;
                }
            }
            openList.remove(best);
            ++this->evaluatedNodes;

            list<State<T>*>* adj = s->getAllPossibleStates(best);
            for(auto &a : *adj) {
                if (a == goal) {
                    a->setCameFrom(best);
                    return this->backTrace(a, s);
                }

                // if in the closed list ignore
                bool isInClosed = false;
                for (auto &c : closedList) {
                    if (c == a) {
                        isInClosed = true;
                        break;
                    }
                }
                if (isInClosed) {
                    continue;
                }

                // if already in open list, check if the total score
                // when we use the current generated path to get there
                // if it is, update its score and _parent
                bool isInOpen = false;
                for (auto &o : openList) {
                    if (o == a) {
                        isInOpen = true;
                        break;
                    }
                }
                if (isInOpen) {
                    if (this->fromHere(best,goal) + toState[best] + a->getCost() < this->fromHere(a,goal) + toState[a]) {
                        a->setCameFrom(best);
                        toState[a]=toState[best]+a->getCost();
                        best = a;
                    }
                    // if not in the open list add it and compute its score
                } else {
                    a->setCameFrom(best);
                    toState[a]=toState[best]+a->getCost();
                    openList.push_back(a);
                }
            }
            closedList.push_back(best);
        */}
    };
