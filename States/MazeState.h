#pragma once
#include <iostream>
#include "State.h"

bool operator!=(const State<pair<int,int>> & l, const State<pair<int,int>> & r) {
    return !(l == r);
}

bool operator==(const State<pair<int,int>> & l, nullptr_t) {
    return l.getState().first < 0 || l.getState().second < 0;
}


using namespace std;
class MazeState : public State<pair<int,int>>
{
public:
    MazeState(State<pair<int, int>>& state) : State(state) {};
    MazeState(int x, int y, State<pair<int, int>>* cameFrom) : State<pair<int, int>>(make_pair(x, y)){
        _cameFrom = cameFrom;
        _cost = calculateCost(cameFrom);
    };

    ~MazeState() {};

    double calculateCost(State<pair<int,int>>* targetState){
        if (!targetState) return 0;
        return abs(_state.first - targetState->getState().first)
        + abs(_state.second - targetState->getState().second);
    }

    friend ostream& operator<< (ostream& stream, const MazeState& s) {
        stream << "(" << s.getState().first << ", " << s.getState().second << ")";
        return stream;
    }
};

